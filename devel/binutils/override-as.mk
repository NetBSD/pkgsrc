# $NetBSD: override-as.mk,v 1.2 2009/06/13 06:46:41 rillig Exp $

# This Makefile fragment can be included by packages that wish to
# override the default selection of as(1) and use the one from devel/binutils
# instead.

GNU_PREFIX_CMD= ${PKG_INFO} -Q GNU_PROGRAM_PREFIX binutils 2>/dev/null \
		|| { cd ${BUILDLINK_PKGSRCDIR.binutils} \
		&& ${MAKE} ${MAKEFLAGS} show-var VARNAME=GNU_PROGRAM_PREFIX; }

PKG_AS=		${PREFIX}/bin/${:!${GNU_PREFIX_CMD}!}as

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
