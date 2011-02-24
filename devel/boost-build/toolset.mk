# $NetBSD: toolset.mk,v 1.5 2011/02/24 11:05:34 adam Exp $

.if !empty(PKGSRC_COMPILER:Mgcc)
.  if ${OPSYS} == "Darwin"
BOOST_TOOLSET=		darwin
.  else
BOOST_TOOLSET=		gcc
.  endif
.elif !empty(PKGSRC_COMPILER:Mclang)
BOOST_TOOLSET=		clang
.elif !empty(PKGSRC_COMPILER:Mmipspro*)
BOOST_TOOLSET=		mipspro
.elif !empty(PKGSRC_COMPILER:Msunpro)
BOOST_TOOLSET=		sunpro
.else
PKG_FAIL_REASON+=	"Unknown compiler ${PKGSRC_COMPILER} for Boost."
.endif
