# $NetBSD: Makefile,v 1.3 2017/01/27 15:45:05 prlw1 Exp $

DISTNAME=	swig-3.0.11
PKGNAME=	${DISTNAME:S/swig/swig3/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator (version 3)
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:build

CONFIGURE_ARGS+=	--program-suffix=3.0
CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/3.0

BUILD_TARGET=	swig

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
