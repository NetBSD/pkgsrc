# $NetBSD: help.mk,v 1.1 2006/10/23 14:40:15 rillig Exp $
#

# This is the integrated pkgsrc online help system. To query for the
# meaning of a variable, run "make help TOPIC=VARNAME". All variables from
# certain pkgsrc Makefile fragments that have inline comments are eligible
# for querying.

.if !defined(_PKGSRC_HELP_MK)
_PKGSRC_HELP_MK=	# defined

_HELP_FILES=		mk/*.mk mk/*/*.mk

.if defined(VARNAME)
TOPIC?=		${VARNAME}
.endif
.if defined(topic)
TOPIC?=		${topic}
.endif

.PHONY: help
help:
.if !defined(TOPIC)
	@${PRINTF} "usage: %s help topic=<topic>\\n" ${MAKE:Q}
	@${PRINTF} "\\n"
	@${PRINTF} "\\t<topic> may be a variable name or a make target,\\n"
	@${PRINTF} "\\tfor example CONFIGURE_DIRS or patch. For convenience,\\n"
	@${PRINTF} "\\tyou don't need to use uppercase letters when typing\\n"
	@${PRINTF} "\\tvariable names.\\n"
	@${PRINTF} "\\n"
.else
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	cd ${PKGSRCDIR};						\
	{ for i in ${_HELP_FILES}; do ${CAT} "$$i"; ${ECHO} ""; done; }	\
	| env TOPIC=${TOPIC:Q} ${AWK} -f ${PKGSRCDIR}/mk/help/help.awk
.endif

.endif
