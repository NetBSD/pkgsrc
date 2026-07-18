# $NetBSD: Makefile,v 1.7 2026/07/18 12:21:58 gdt Exp $

VERSION=	1.1.0
DISTTAIL=	spartn
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pyspartn/
COMMENT=	Python parser for SPARTN (u-blox differential protocol)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
