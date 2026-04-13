# $NetBSD: Makefile,v 1.18 2026/04/13 13:15:39 kikadf Exp $

.include "Makefile.common"

DISTNAME=	vulkan-headers-${SDK_VERSION}
CATEGORIES=	graphics
GITHUB_PROJECT=	Vulkan-Headers
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Headers
COMMENT=	Headers for Vulkan Graphics API
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

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
