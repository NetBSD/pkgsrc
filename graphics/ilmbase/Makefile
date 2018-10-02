# $NetBSD: Makefile,v 1.20 2018/10/02 12:05:35 adam Exp $

DISTNAME=	ilmbase-2.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=openexr/}
GITHUB_PROJECT=	openexr
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake
GNU_CONFIGURE=		yes
TEST_TARGET=		check
LIBS.SunOS=		-lm
CONFIG_SHELL=		bash

PKGCONFIG_OVERRIDE=	IlmBase.pc.in
PTHREAD_OPTS=		require

CONFLICTS=		openexr<1.6

BUILDLINK_TRANSFORM+=	rm:-Wno-long-double

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
