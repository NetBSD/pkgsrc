# $NetBSD: help.mk,v 1.12 2016/02/01 18:47:23 leot Exp $
#

# This is the integrated pkgsrc online help system. To query for the
# meaning of a variable, run "make help TOPIC=VARNAME". All variables from
# certain pkgsrc Makefile fragments that have inline comments are eligible
# for querying.

_HELP_FILES=		Makefile
_HELP_FILES+=		mk/*.mk mk/*/*.mk mk/*/*/*.mk
_HELP_FILES+=		mk/defaults/mk.conf
_HELP_FILES+=		lang/go/*.mk
_HELP_FILES+=		lang/perl5/*.mk lang/php/*.mk lang/python/*.mk
_HELP_FILES+=		lang/ruby/*.mk
_HELP_FILES+=		print/texlive/*.mk
_HELP_FILES+=		mk/*/*.help
.if exists(${.PARSEDIR}/../../wip/mk)
_HELP_FILES+=		wip/mk/*.mk
.endif

.if defined(VARNAME)
TOPIC?=		${VARNAME}
.endif
.if defined(topic)
TOPIC?=		${topic}
.endif

.PHONY: help
help:
.if !defined(TOPIC)
	@${ECHO} "usage: "${MAKE:Q}" help topic=<topic>"
	@${ECHO} ""
	@${ECHO} "	<topic> may be a variable name or a make target,"
	@${ECHO} "	for example CONFIGURE_DIRS or patch. For convenience,"
	@${ECHO} "	you don't need to use uppercase letters when typing"
	@${ECHO} "	variable names."
	@${ECHO} ""
.else
	${RUN} cd ${PKGSRCDIR};						\
	env TOPIC=${TOPIC:Q} ${AWK} -f ${PKGSRCDIR}/mk/help/help.awk ${_HELP_FILES}
.endif
