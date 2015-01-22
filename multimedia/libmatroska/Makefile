# $NetBSD: Makefile,v 1.34 2015/01/22 12:57:27 pho Exp $

DISTNAME=	libmatroska-1.4.2
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE=	libmatroska.pc.in

GNU_CONFIGURE=		yes
TEST_TARGET=		test

BUILDLINK_API_DEPENDS.libebml+=	libebml>=1.3.1
.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
