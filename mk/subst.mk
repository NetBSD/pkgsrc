# $NetBSD: subst.mk,v 1.3.2.1 2003/12/11 09:55:31 agc Exp $
#
# This Makefile fragment implements a general text replacement facility
# for different classes of files in ${WRKSRC}.  For each class of files,
# a target <class>-subst is created to perform the text replacement.
#
# The following variables are used:
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

ECHO_SUBST_MSG?=	${ECHO}

# _SUBST_IS_TEXT_FILE returns 0 if $${file} is a text file.
_SUBST_IS_TEXT_FILE?= \
	${FILE_CMD} $${file} | ${EGREP} "(shell script|text)" >/dev/null 2>&1

.for _class_ in ${SUBST_CLASSES}
_SUBST_COOKIE.${_class_}=	${WRKDIR}/.subst_${_class_}_done

.if defined(SUBST_SED.${_class_}) && !empty(SUBST_SED.${_class_})
SUBST_FILTER_CMD.${_class_}?=	${SED} ${SUBST_SED.${_class_}}
.else
SUBST_FILTER_CMD.${_class_}?=	# empty
.endif

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
.if defined(SUBST_MESSAGE.${_class_})
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_SUBST_MSG} "=> ${SUBST_MESSAGE.${_class_}}"
.endif

.PHONY: subst-${_class_}-cookie
 subst-${_class_}-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TOUCH} ${TOUCH_FLAGS} ${_SUBST_COOKIE.${_class_}}

${_SUBST_COOKIE.${_class_}}:
.  if !empty(SUBST_FILTER_CMD.${_class_})
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC};							\
	files="${SUBST_FILES.${_class_}}";				\
	case "$$files" in						\
	"")	;;							\
	*)	for file in $${files}; do				\
			if ${_SUBST_IS_TEXT_FILE}; then			\
				${MV} -f $$file $$file.subst.sav;	\
				${CAT} $$file.subst.sav 		\
					| ${SUBST_FILTER_CMD.${_class_}} \
					> $$file;			\
				if [ -x $$file.subst.sav ]; then	\
					${CHMOD} +x $$file;		\
				fi;					\
				if ${CMP} -s $$file.subst.sav $$file; then \
					${MV} -f $$file.subst.sav $$file; \
				else					\
					${ECHO} $$file >> ${.TARGET};	\
				fi;					\
			fi;						\
		done ;;							\
	esac
.  endif
.endfor
