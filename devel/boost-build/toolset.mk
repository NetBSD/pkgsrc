# $NetBSD: toolset.mk,v 1.1 2005/02/26 22:48:35 jmmv Exp $

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mgcc)
BOOST_TOOLSET=		gcc
.elif !empty(PKGSRC_COMPILER:Mmipspro*)
BOOST_TOOLSET=		mipspro
.elif !empty(PKGSRC_COMPILER:Msunpro)
BOOST_TOOLSET=		sunpro
.else
BROKEN+=		"Unknown compiler ${PKGSRC_COMPILER} for Boost"
.endif
