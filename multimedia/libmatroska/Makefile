# $NetBSD: Makefile,v 1.43 2018/04/22 21:40:00 adam Exp $

DISTNAME=	libmatroska-1.4.9
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

BUILDLINK_API_DEPENDS.libebml+=	libebml>=1.3.6
.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
