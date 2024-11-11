# $NetBSD: Makefile,v 1.3 2024/11/11 07:28:55 wiz Exp $

DISTNAME=	nvdlib-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python www
MASTER_SITES=	${MASTER_SITE_GITHUB:=vehemont/}
GITHUB_PROJECT=	nvdlib
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Vehemont/nvdlib
COMMENT=	National Vulnerability Database CPE/CVE API Library for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0.18:../../net/py-responses

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
