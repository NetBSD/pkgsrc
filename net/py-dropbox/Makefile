# $NetBSD: Makefile,v 1.21 2026/10/26 05:49:35 adam Exp $

DISTNAME=	dropbox-12.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dropbox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dropbox.com/developers
COMMENT=	Dropbox Python API
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.16.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stone>=2.0:../../net/py-stone
# tests not included in pypi distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=0:../../devel/py-coverage
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
