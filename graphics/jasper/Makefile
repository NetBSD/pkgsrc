# $NetBSD: Makefile,v 1.50 2017/11/23 19:16:28 snj Exp $

DISTNAME=	jasper-2.0.14
CATEGORIES=	graphics
MASTER_SITES=	http://www.ece.uvic.ca/~mdadams/jasper/software/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ece.uvic.ca/~mdadams/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec
LICENSE=	modified-bsd

USE_CMAKE=		yes
USE_LANGUAGES=		c99 c++
CMAKE_ARGS+=		-DALLOW_IN_SOURCE_BUILD=ON

PKGCONFIG_OVERRIDE=	pkgconfig/jasper.pc

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
