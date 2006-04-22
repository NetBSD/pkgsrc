# $NetBSD: toolset.mk,v 1.3 2006/04/22 09:22:07 rillig Exp $

.include "../../mk/compiler.mk"

.if ${OPSYS} == "Darwin"
BOOST_TOOLSET=		darwin
.elif !empty(PKGSRC_COMPILER:Mgcc)
BOOST_TOOLSET=		gcc
.elif !empty(PKGSRC_COMPILER:Mmipspro*)
BOOST_TOOLSET=		mipspro
.elif !empty(PKGSRC_COMPILER:Msunpro)
BOOST_TOOLSET=		sunpro
.else
PKG_FAIL_REASON+=	"Unknown compiler ${PKGSRC_COMPILER} for Boost."
.endif
