# $NetBSD: Makefile,v 1.42 2017/09/27 06:42:42 adam Exp $

DISTNAME=	libmatroska-1.4.8
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libmatroska.pc.in

BUILDLINK_API_DEPENDS.libebml+=	libebml>=1.3.4
.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
