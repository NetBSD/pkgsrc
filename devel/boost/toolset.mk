# $NetBSD: toolset.mk,v 1.2 2004/07/04 02:55:42 tv Exp $
# Translation from PKGSRC_COMPILER to BOOST_TOOLSET.

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mgcc)
BOOST_TOOLSET=		gcc
.elif !empty(PKGSRC_COMPILER:Mmipspro*)
BOOST_TOOLSET=		mipspro
.elif !empty(PKGSRC_COMPILER:Msunpro)
BOOST_TOOLSET=		sunpro
.else
BROKEN+=		"unknown compiler ${PKGSRC_COMPILER} for Boost"
.endif
