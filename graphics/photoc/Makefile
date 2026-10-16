# $NetBSD: Makefile,v 1.1 2026/10/16 00:43:50 ktnb Exp $

DISTNAME=	photoc-0.7.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ahmetomerv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/ahmetomerv/photoc/
COMMENT=	Command-line tools for photographers
LICENSE=	mit

USE_TOOLS=	pkg-config

WRKSRC=	${WRKDIR}/${DISTNAME}

.include "../../devel/cmake/build.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
