# $NetBSD: Makefile,v 1.1 2021/01/24 18:57:46 maya Exp $

GITHUB_PROJECT=	Vulkan-Headers
DISTNAME=	sdk-1.1.126.0
PKGNAME=	${GITHUB_PROJECT:tl}-${DISTNAME:S/sdk-//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	${DISTNAME}
EXTRACT_USING=	bsdtar

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Headers/
COMMENT=	Headers for Vulkan Graphics API
LICENSE=	apache-2.0

USE_CMAKE=	yes

REPLACE_PYTHON=	registry/*.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
