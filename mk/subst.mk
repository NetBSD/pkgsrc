# $NetBSD: subst.mk,v 1.18 2005/05/17 19:01:36 rillig Exp $
#
# This Makefile fragment implements a general text replacement facility.
# Package makefiles define a ``class'', for each of which a paricular
# substitution description can be defined.  For each class of files, a
# target subst-<class> is created to perform the text replacement.
#
# The following variables are used:
#
# SUBST_CLASSES
#	A list of class names. 	A new class name must be appended (+=).
#
# SUBST_STAGE.<class>
#	"stage" at which we do the text replacement, e.g. pre-configure,
#	post-build, etc.
#
# SUBST_MESSAGE.<class>
#	message to display, noting what is being substituted
#
# SUBST_FILES.<class>
#	files on which to run the substitution; these are relative to
#	${WRKSRC}
#
# SUBST_SED.<class>
#	sed(1) substitution expression to run on the specified files
#
# SUBST_FILTER_CMD.<class>
#	filter used to perform the actual substitution on the specified
#	files.  Defaults to ${SED} ${SUBST_SED.<class>}.
#
# SUBST_POSTCMD.<class>
#	command to clean up after sed(1). Defaults to ${RM} -f
#	$$file${_SUBST_BACKUP_SUFFIX}. For debugging, set it to ${DO_NADA}.

ECHO_SUBST_MSG?=	${ECHO}

# _SUBST_IS_TEXT_FILE returns 0 if $${file} is a text file.
_SUBST_IS_TEXT_FILE?= \
	{ ${TEST} -f "$$file"						\
	  && ${FILE_CMD} "$$file"					\
	     | ${EGREP} "(executable .* script|shell script|text)";	\
	} >/dev/null 2>&1

_SUBST_BACKUP_SUFFIX=	.subst.sav

.for _class_ in ${SUBST_CLASSES}
_SUBST_COOKIE.${_class_}=	${WRKDIR}/.subst_${_class_}_done

SUBST_FILTER_CMD.${_class_}?=	${SED} ${SUBST_SED.${_class_}}
SUBST_POSTCMD.${_class_}?=	${RM} -f "$$tmpfile"

SUBST_TARGETS+=			subst-${_class_}
_SUBST_TARGETS.${_class_}=	subst-${_class_}-message
_SUBST_TARGETS.${_class_}+=	${_SUBST_COOKIE.${_class_}}
_SUBST_TARGETS.${_class_}+=	subst-${_class_}-cookie

.ORDER: ${_SUBST_TARGETS.${_class_}}

.  if defined(SUBST_STAGE.${_class_})
${SUBST_STAGE.${_class_}}: subst-${_class_}
.  endif

.PHONY: subst-${_class_}
subst-${_class_}: ${_SUBST_TARGETS.${_class_}}

.PHONY: subst-${_class_}-message
 subst-${_class_}-message:
.  if defined(SUBST_MESSAGE.${_class_})
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_SUBST_MSG} "=> "${SUBST_MESSAGE.${_class_}:Q}
.  endif

.PHONY: subst-${_class_}-cookie
 subst-${_class_}-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TOUCH} ${TOUCH_FLAGS} ${_SUBST_COOKIE.${_class_}}

${_SUBST_COOKIE.${_class_}}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC:Q};							\
	files=${SUBST_FILES.${_class_}:Q};				\
	for file in $$files; do						\
		file="./$$file";					\
		tmpfile="$$file"${_SUBST_BACKUP_SUFFIX:Q};		\
		if ${_SUBST_IS_TEXT_FILE}; then				\
			${MV} -f "$$file" "$$tmpfile" || exit 1;	\
			${CAT} "$$tmpfile"				\
			| ${SUBST_FILTER_CMD.${_class_}}		\
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
		fi;							\
	done
.endfor
