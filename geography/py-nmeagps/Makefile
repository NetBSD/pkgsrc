# $NetBSD: Makefile,v 1.10 2026/04/27 12:51:41 wiz Exp $

VERSION=	1.1.4
DISTTAIL=	nmeagps
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pynmeagps
COMMENT=	Python parser for NMEA 0183 (GNSS-relevant subset)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
