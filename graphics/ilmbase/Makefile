# $NetBSD: Makefile,v 1.22 2019/07/08 10:36:27 nia Exp $

DISTNAME=	ilmbase-2.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=openexr/}
GITHUB_PROJECT=	openexr
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake
GNU_CONFIGURE=		yes
GCC_REQD+=		6
TEST_TARGET=		check
LIBS.SunOS=		-lm
CONFIG_SHELL=		bash

PKGCONFIG_OVERRIDE=	IlmBase.pc.in
PTHREAD_OPTS=		require

CONFLICTS=		openexr<1.6

BUILDLINK_TRANSFORM+=	rm:-Wno-long-double

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
