# $NetBSD: Makefile,v 1.2 2016/09/19 17:49:23 prlw1 Exp $

DISTNAME=	swig-3.0.10
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
