# $NetBSD: Makefile,v 1.1 2025/09/04 13:04:51 gdt Exp $

VERSION=	1.1.9
DISTTAIL=	rtcm
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pyrtcm/
COMMENT=	Python parser for RTCM3 (differential/RTK GNSS)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
