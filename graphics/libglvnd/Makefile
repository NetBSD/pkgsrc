# $NetBSD: Makefile,v 1.3 2019/09/09 10:08:54 nia Exp $

DISTNAME=	libglvnd-1.1.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=NVIDIA/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NVIDIA/libglvnd
COMMENT=	GL Vendor-Neutral Dispatch library
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	tool

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=../../src/GLdispatch/export_list_tls.ver

.include "../../lang/python/tool.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
