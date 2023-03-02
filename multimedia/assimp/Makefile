# $NetBSD: Makefile,v 1.7 2023/03/02 16:25:49 tnn Exp $

DISTNAME=	assimp-5.2.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=assimp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	http://www.assimp.org/
COMMENT=	Library to import various 3D model formats
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	assimp.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
