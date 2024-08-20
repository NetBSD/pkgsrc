# $NetBSD: Makefile,v 1.2 2024/08/20 05:41:18 thorpej Exp $

OFPGAL_VERSION=0.12.1

GITHUB_PROJECT=	openFPGALoader
GITHUB_TAG=	v${OFPGAL_VERSION}

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${OFPGAL_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=trabucayre/}

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://trabucayre.github.io/openFPGALoader/
COMMENT=	A universal utility for programming FPGAs
LICENSE=	apache-2.0

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.include "../../comms/libhidapi/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libftdi1/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
