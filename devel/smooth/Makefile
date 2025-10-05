# $NetBSD: Makefile,v 1.4 2025/10/05 19:25:51 js Exp $

DISTNAME=	smooth-0.9.10
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=smooth/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.smooth-project.org/
COMMENT=	Multi platform object oriented C++ class library
LICENSE=	artistic-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# For build and install targets
MAKE_FLAGS+=	config="systemlibbz2 systemlibcpuid systemlibcurl systemlibfribidi systemlibiconv systemlibjpeg systemlibpng systemlibwebp systemlibxml2 systemzlib"
MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../sysutils/libcpuid/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
