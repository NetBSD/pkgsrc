# $NetBSD: Makefile,v 1.49 2022/10/03 11:51:38 adam Exp $

DISTNAME=	libmatroska-1.7.0
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_LANGUAGES=		c c++14
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON
PKGCONFIG_OVERRIDE=	libmatroska.pc.in

BUILDLINK_API_DEPENDS.libebml+=	libebml>=1.4.3
.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
