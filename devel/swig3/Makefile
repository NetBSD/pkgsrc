# $NetBSD: Makefile,v 1.10 2022/06/28 11:33:44 wiz Exp $

DISTNAME=	swig-3.0.12
PKGNAME=	${DISTNAME:S/swig/swig3/}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator (version 3)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:build
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configure
CONFIGURE_ARGS+=	--program-suffix=3.0
CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/3.0

BUILD_TARGET=	swig

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
