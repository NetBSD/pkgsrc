# $NetBSD: subst.mk,v 1.53 2008/01/26 15:23:21 rillig Exp $
#
# This Makefile fragment implements a general text replacement facility.
# Package makefiles define a ``class'', for each of which a particular
# substitution description can be defined.  For each class of files, a
# target subst-<class> is created to perform the text replacement.
#
# Package-settable variables:
#
# SUBST_CLASSES
#	A list of class names.  When adding new classes to this list, be
#	sure to append them (+=) instead of overriding them (=).
#
# SUBST_STAGE.<class>
#	"stage" at which we do the text replacement. Should be one of
#	{pre,do,post}-{extract,patch,configure,build,install}.
#
# SUBST_MESSAGE.<class>
#	The message to display before doing the substitution.
#
# SUBST_FILES.<class>
#	A list of file patterns on which to run the substitution;
#	the filenames are either absolute or relative to ${WRKSRC}.
#
# SUBST_SED.<class>
#	List of sed(1) arguments to run on the specified files. Multiple
#	commands can be specified using the -e option of sed.
#
# SUBST_VARS.<class>
#	List of variables that are substituted whenever they appear in
#	the form @VARNAME@. This is basically a short-cut for
#
#		-e 's,@VARNAME@,${VARNAME},g'
#
#	also taking care of (most) quoting issues. You can use both
#	SUBST_SED and SUBST_VARS in a single class.
#
# SUBST_FILTER_CMD.<class>
#	Filter used to perform the actual substitution on the specified
#	files.  Defaults to ${SED} ${SUBST_SED.<class>}.
#
# SUBST_POSTCMD.<class>
#	Command to clean up after sed(1). Defaults to ${RM} -f
#	$$file${_SUBST_BACKUP_SUFFIX}. For debugging, set it to ${DO_NADA}.
#
# SUBST_SKIP_TEXT_CHECK.<class>
#	By default, each file is checked whether it really is a text file
#	before any substitutions are done to it. Since that test is not
#	perfect, it can be disabled by setting this variable to "yes".
#
# See also:
#	PLIST_SUBST
#
# Keywords: subst
#

_VARGROUPS+=		subst
_PKG_VARS.subst=	SUBST_CLASSES
.for c in ${SUBST_CLASSES}
.  for pv in SUBST_STAGE SUBST_MESSAGE SUBST_FILES SUBST_SED SUBST_VARS	\
	SUBST_FILTER_CMD SUBST_POSTCMD SUBST_SKIP_TEXT_CHECK
_PKG_VARS.subst+=	${pv}.${c}
.  endfor
.endfor

ECHO_SUBST_MSG?=	${STEP_MSG}

# _SUBST_IS_TEXT_FILE returns 0 if $${file} is a text file.
_SUBST_IS_TEXT_FILE?= \
	{ nchars=`${WC} -c < "$$file"`;					\
	  notnull=`LC_ALL=C ${TR} -d '\\0' < "$$file" | ${WC} -c`;	\
	  [ "$$nchars" = "$$notnull" ] || ${FALSE} ;			\
	}

_SUBST_BACKUP_SUFFIX=	.subst.sav

.for _class_ in ${SUBST_CLASSES}
_SUBST_COOKIE.${_class_}=	${WRKDIR}/.subst_${_class_}_done

SUBST_FILTER_CMD.${_class_}?=	${SED} ${SUBST_SED.${_class_}}
SUBST_VARS.${_class_}?=		# none
SUBST_MESSAGE.${_class_}?=	Substituting "${_class_}" in ${SUBST_FILES.${_class_}}
.  for v in ${SUBST_VARS.${_class_}}
SUBST_FILTER_CMD.${_class_} +=	-e s,@${v}@,${${v}:S|\\|\\\\|gW:S|,|\\,|gW:S|&|\\\&|gW:Q},g
.  endfor
SUBST_POSTCMD.${_class_}?=	${RM} -f "$$tmpfile"
SUBST_SKIP_TEXT_CHECK.${_class_}?=	no

.if !empty(SUBST_SKIP_TEXT_CHECK.${_class_}:M[Yy][Ee][Ss])
_SUBST_IS_TEXT_FILE.${_class_}=	${TRUE}
.else
_SUBST_IS_TEXT_FILE.${_class_}=	${_SUBST_IS_TEXT_FILE}
.endif

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
.  if !empty(SUBST_MESSAGE.${_class_})
	${RUN} ${ECHO_SUBST_MSG} ${SUBST_MESSAGE.${_class_}:Q}
.  endif
	${RUN} cd ${WRKSRC:Q};						\
	files=${SUBST_FILES.${_class_}:Q};				\
	for file in $$files; do						\
		case $$file in /*) ;; *) file="./$$file";; esac;	\
		tmpfile="$$file"${_SUBST_BACKUP_SUFFIX:Q};		\
		if [ ! -f "$$file" ]; then				\
			${WARNING_MSG} "[subst.mk:${_class_}] Ignoring non-existent file \"$$file\"."; \
		elif ${_SUBST_IS_TEXT_FILE.${_class_}}; then		\
			${MV} -f "$$file" "$$tmpfile" || exit 1;	\
			${SUBST_FILTER_CMD.${_class_}}			\
			< "$$tmpfile"					\
			> "$$file";					\
			if ${TEST} -x "$$tmpfile"; then			\
				${CHMOD} +x "$$file";			\
			fi;						\
			if ${CMP} -s "$$tmpfile" "$$file"; then 	\
				${INFO_MSG} "[subst.mk:${_class_}] Nothing changed in $$file."; \
				${MV} -f "$$tmpfile" "$$file";		\
			else						\
				${SUBST_POSTCMD.${_class_}};		\
				${ECHO} "$$file" >> ${.TARGET};		\
			fi;						\
		else							\
			${WARNING_MSG} "[subst.mk:${_class_}] Ignoring non-text file \"$$file\"."; \
		fi;							\
	done
	${RUN} ${TOUCH} ${TOUCH_FLAGS} ${.TARGET:Q}
.endfor
