# $NetBSD: Makefile,v 1.16 2025/12/22 14:43:12 adam Exp $

DISTNAME=	vulkan-headers-1.4.335
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=	Vulkan-Headers
GITHUB_TAG=	vulkan-sdk-${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Headers
COMMENT=	Headers for Vulkan Graphics API
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=	c c++

REPLACE_PYTHON+=	registry/*.py
REPLACE_PYTHON+=	registry/spec_tools/*.py

.include "../../mk/bsd.prefs.mk"

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
