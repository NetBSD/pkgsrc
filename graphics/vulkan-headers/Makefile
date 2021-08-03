# $NetBSD: Makefile,v 1.2 2021/08/03 16:00:26 triaxx Exp $

GITHUB_PROJECT=	Vulkan-Headers
DISTNAME=	sdk-1.2.182.0
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
