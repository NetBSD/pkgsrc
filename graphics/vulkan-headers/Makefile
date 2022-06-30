# $NetBSD: Makefile,v 1.4 2022/06/30 11:18:29 nia Exp $

GITHUB_PROJECT=	Vulkan-Headers
DISTNAME=	v1.3.204
PKGNAME=	${GITHUB_PROJECT:tl}-${DISTNAME:S/^v//}
PKGREVISION=	1
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
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
