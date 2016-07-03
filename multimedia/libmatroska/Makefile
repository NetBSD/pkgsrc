# $NetBSD: Makefile,v 1.39 2016/07/03 11:13:24 wiz Exp $

DISTNAME=	libmatroska-1.4.5
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

BUILDLINK_API_DEPENDS.libebml+=	libebml>=1.3.4
.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
