# $NetBSD: bsd.pkg.error.mk,v 1.2 2006/06/14 15:09:34 jlam Exp $

ERROR_DIR=	${WRKDIR}/.error
WARNING_DIR=	${WRKDIR}/.warning

# Macros for outputting delayed error and warning messages that are
# picked up by the error-check target and can be used in place of
# ${ECHO}.  We output to files that are named without leading dots.
#
DELAYED_ERROR_MSG?=	${ECHO} >> ${ERROR_DIR}/${.TARGET:T:C/^[.]*//:Q}
DELAYED_WARNING_MSG?=	${ECHO} >> ${WARNING_DIR}/${.TARGET:T:C/^[.]*//:Q}

makedirs: ${ERROR_DIR} ${WARNING_DIR}
${ERROR_DIR} ${WARNING_DIR}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${.TARGET}

.PHONY: error-check

######################################################################
### error-check (PRIVATE)
######################################################################
### error-check is a macro target that will peek in the warning and
### error directories to check for the presence of any files.  If they
### exist and are non-empty, then they are assumed to be message files
### and will be outputted then removed.  If they are from the error
### directory, then the target will fail.
###
error-check: .USE
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${WARNING_DIR}/*.tmp;					\
	${TEST} -d ${WARNING_DIR} || exit 0;				\
	cd ${WARNING_DIR};						\
	for file in ./*; do						\
		${TEST} "$$file" != "./*" || exit 0;			\
		break;							\
	done;								\
	${CAT} ./* | ${WARNING_CAT};					\
	${RM} -f ./*

	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${ERROR_DIR}/*.tmp;					\
	${TEST} -d ${ERROR_DIR} || exit 0;				\
	cd ${ERROR_DIR};						\
	for file in ./*; do						\
		${TEST} "$$file" != "./*" || exit 0;			\
		break;							\
	done;								\
	${CAT} * | ${ERROR_CAT};					\
	if ${_NONZERO_FILESIZE_P} ./*; then				\
		${RM} -f ./*;						\
		exit 1;							\
	fi

######################################################################
### error-clean (PRIVATE)
######################################################################
### error-clean removes the error and warning directory and files.
###
error-clean:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -fr ${ERROR_DIR} ${WARNING_DIR}
