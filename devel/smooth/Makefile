# $NetBSD: Makefile,v 1.1 2025/08/12 00:54:26 ryoon Exp $

DISTNAME=	smooth-0.9.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=smooth/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.smooth-project.org/
COMMENT=	Multi platform object oriented C++ class library
LICENSE=	artistic-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# For build and install targets
MAKE_FLAGS+=	config="systemlibcpuid systemlibwebp"
MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../sysutils/libcpuid/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
