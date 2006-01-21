# $NetBSD: toolset.mk,v 1.2 2006/01/21 09:02:16 jmmv Exp $

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
BROKEN+=		"Unknown compiler ${PKGSRC_COMPILER} for Boost"
.endif
