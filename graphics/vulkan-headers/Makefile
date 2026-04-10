# $NetBSD: Makefile,v 1.17 2026/04/10 20:15:06 wiz Exp $

DISTNAME=	vulkan-headers-1.4.349
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=	Vulkan-Headers
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Headers
COMMENT=	Headers for Vulkan Graphics API
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
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
