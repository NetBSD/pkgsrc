# $NetBSD: toolset.mk,v 1.1 2004/06/06 23:51:36 tv Exp $
# Translation from PKGSRC_COMPILER to BOOST_TOOLSET.

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mgcc)
BOOST_TOOLSET=		gcc
.elif !empty(PKGSRC_COMPILER:Mmipspro*)
BOOST_TOOLSET=		mipspro
.elif !empty(PKGSRC_COMPILER:Msunpro)
BOOST_TOOLSET=		sunpro
.else
.error unknown BOOST_TOOLSET
.endif
