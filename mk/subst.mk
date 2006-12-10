# $NetBSD: subst.mk,v 1.38 2006/12/10 02:25:13 reed Exp $
#
# This Makefile fragment implements a general text replacement facility.
# Package makefiles define a ``class'', for each of which a particular
# substitution description can be defined.  For each class of files, a
# target subst-<class> is created to perform the text replacement.
#
# Package-settable variables:
#
# SUBST_CLASSES
#	A list of class names. 	A new class name must be appended (+=).
#
# SUBST_STAGE.<class>
#	"stage" at which we do the text replacement. Should be one of
#	{pre,do,post}-{extract,patch,configure,build,install}.
#
# SUBST_MESSAGE.<class>
#	The message to display when the substitution is done.
#
# SUBST_FILES.<class>
#	A list of file patterns on which to run the substitution;
#	the filenames are either absolute or relative to ${WRKSRC}.
#
# SUBST_SED.<class>
#	List of sed(1) arguments to run on the specified files. Multiple
#	commands can be specified using the -e option of sed.
#
# SUBST_FILTER_CMD.<class>
#	Filter used to perform the actual substitution on the specified
#	files.  Defaults to ${SED} ${SUBST_SED.<class>}.
#
# SUBST_POSTCMD.<class>
#	Command to clean up after sed(1). Defaults to ${RM} -f
#	$$file${_SUBST_BACKUP_SUFFIX}. For debugging, set it to ${DO_NADA}.

ECHO_SUBST_MSG?=	${STEP_MSG}

# _SUBST_IS_TEXT_FILE returns 0 if $${file} is a text file.
_SUBST_IS_TEXT_FILE?= \
	{ ${TEST} -f "$$file"						\
	  && ${FILE_CMD} "$$file"					\
	     | ${EGREP} "(executable .* script|shell script|text|Assembler source|libtool)";	\
	} >/dev/null 2>&1

_SUBST_BACKUP_SUFFIX=	.subst.sav

.for _class_ in ${SUBST_CLASSES}
_SUBST_COOKIE.${_class_}=	${WRKDIR}/.subst_${_class_}_done

SUBST_FILTER_CMD.${_class_}?=	${SED} ${SUBST_SED.${_class_}}
SUBST_POSTCMD.${_class_}?=	${RM} -f "$$tmpfile"

SUBST_TARGETS+=			subst-${_class_}

.  if defined(SUBST_STAGE.${_class_})
${SUBST_STAGE.${_class_}}: subst-${_class_}
.  else
# SUBST_STAGE.* does not need to be defined.
#PKG_FAIL_REASON+=	"SUBST_STAGE missing for ${_class_}."
.  endif

.PHONY: subst-${_class_}
subst-${_class_}: ${_SUBST_COOKIE.${_class_}}

${_SUBST_COOKIE.${_class_}}:
.  if defined(SUBST_MESSAGE.${_class_})
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_SUBST_MSG} ${SUBST_MESSAGE.${_class_}:Q}
.  endif
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	cd ${WRKSRC:Q};							\
	files=${SUBST_FILES.${_class_}:Q};				\
	for file in $$files; do						\
		case $$file in /*) ;; *) file="./$$file";; esac;	\
		tmpfile="$$file"${_SUBST_BACKUP_SUFFIX:Q};		\
		if ${_SUBST_IS_TEXT_FILE}; then				\
			${MV} -f "$$file" "$$tmpfile" || exit 1;	\
			${SUBST_FILTER_CMD.${_class_}}			\
			< "$$tmpfile"					\
			> "$$file";					\
			if ${TEST} -x "$$tmpfile"; then			\
				${CHMOD} +x "$$file";			\
			fi;						\
			if ${CMP} -s "$$tmpfile" "$$file"; then 	\
				${MV} -f "$$tmpfile" "$$file";		\
			else						\
				${SUBST_POSTCMD.${_class_}};		\
				${ECHO} "$$file" >> ${.TARGET};		\
			fi;						\
		elif ${TEST} -f "$$file"; then				\
			${WARNING_MSG} "[subst.mk] Ignoring non-text file \"$$file\"." 1>&2; \
		else							\
			${WARNING_MSG} "[subst.mk] Ignoring non-existent file \"$$file\"." 1>&2; \
		fi;							\
	done
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	${TOUCH} ${TOUCH_FLAGS} ${.TARGET:Q}
.endfor
