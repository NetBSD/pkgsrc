# $NetBSD: Makefile,v 1.17 2017/05/14 00:16:36 ryoon Exp $

DISTNAME=	ilmbase-2.2.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.savannah.nongnu.org/releases/openexr/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		ksh gmake
GNU_CONFIGURE=		yes
TEST_TARGET=		check
LIBS.SunOS=		-lm
CONFIG_SHELL=		ksh

PKGCONFIG_OVERRIDE=	IlmBase.pc.in
PTHREAD_OPTS=		require

CONFLICTS=		openexr<1.6

BUILDLINK_TRANSFORM+=	rm:-Wno-long-double

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
