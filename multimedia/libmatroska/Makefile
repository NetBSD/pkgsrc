# $NetBSD: Makefile,v 1.47 2020/08/02 20:18:53 adam Exp $

DISTNAME=	libmatroska-1.6.2
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=YES
PKGCONFIG_OVERRIDE=	libmatroska.pc.in

BUILDLINK_API_DEPENDS.libebml+=	libebml>=1.4.0
.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
