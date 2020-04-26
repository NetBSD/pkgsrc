# $NetBSD: Makefile,v 1.52 2020/04/26 10:05:46 rillig Exp $

DISTNAME=	jasper-2.0.16
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mdadams/}
GITHUB_TAG=	version-${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ece.uvic.ca/~mdadams/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/jasper-${GITHUB_TAG}
USE_CMAKE=		yes
USE_LANGUAGES=		c99 c++
CMAKE_ARGS+=		-DALLOW_IN_SOURCE_BUILD=ON

PKGCONFIG_OVERRIDE=	build/jasper.pc.in

.include "options.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
