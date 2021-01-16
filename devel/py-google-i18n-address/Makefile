# $NetBSD: Makefile,v 1.1 2021/01/16 19:10:29 riastradh Exp $

DISTNAME=	google-i18n-address-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-i18-address/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirumee/google-i18n-address
COMMENT=	Python library for internationalized address formatting
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests

TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
