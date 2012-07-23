# $NetBSD: override-as.mk,v 1.5 2012/07/23 12:24:34 jperkin Exp $

# This Makefile fragment can be included by packages that wish to
# override the default selection of as(1) and use the one from devel/binutils
# instead.

PKG_AS=		${PREFIX}/gnu/bin/as

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mgcc)

SPECS_AS=		${WRAPPER_DIR}/specs.as
WRAPPER_TARGETS+=	${SPECS_AS}

${SPECS_AS}:
	@${ECHO} "*invoke_as:" > ${SPECS_AS}
	@${ECHO} "%{!S:-o %|.s |" >> ${SPECS_AS}
	@${ECHO} "${PKG_AS} %(asm_options) %m.s %A }" >> ${SPECS_AS}

_WRAP_EXTRA_ARGS.CC+=	-specs ${SPECS_AS}
_WRAP_EXTRA_ARGS.CXX+=	-specs ${SPECS_AS}

.endif
