# $NetBSD: Makefile,v 1.22 2026/08/04 20:29:06 wiz Exp $

DISTNAME=	blitz-0.8
PKGNAME=	blitz++-0.8
PKGREVISION=	3
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blitz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oonumerics.org/blitz/
COMMENT=	C++ template class library providing array objects

USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
INFO_FILES=		yes

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:MIntel*)
COMPILER_SPECIFIC_HEADER=	intel
.elif !empty(CC_VERSION:MIBM*)
COMPILER_SPECIFIC_HEADER=	ibm
.elif !empty(CC_VERSION:MCCC*)
COMPILER_SPECIFIC_HEADER=	compaq
.elif !empty(CC_VERSION:Mhp*)
COMPILER_SPECIFIC_HEADER=	hp
.elif !empty(CC_VERSION:MMIPSpro*)
COMPILER_SPECIFIC_HEADER=	sgi
.elif !empty(CC_VERSION:Mgcc*)
COMPILER_SPECIFIC_HEADER=	gnu
.endif
.if defined(COMPILER_SPECIFIC_HEADER)
CONFIGURE_ENV+=			COMPILER_SPECIFIC_HEADER=${COMPILER_SPECIFIC_HEADER}/bzconfig.h
.endif
PLIST_SUBST+=			COMPILER_SPECIFIC_HEADER=${COMPILER_SPECIFIC_HEADER:Dinclude/blitz/${COMPILER_SPECIFIC_HEADER}/bzconfig.h:U@comment}

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
