# $NetBSD: Makefile,v 1.12 2018/02/05 08:58:06 adam Exp $

DISTNAME=	lz4-0.21.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lz4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-lz4/python-lz4
COMMENT=	Python LZ4 binding
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-deprecation-[0-9]*:../../devel/py-deprecation
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-pkgconfig-[0-9]*:../../devel/py-pkgconfig
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

.include "../../archivers/lz4/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
