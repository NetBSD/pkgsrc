# $NetBSD: Makefile,v 1.6 2017/12/31 18:48:57 adam Exp $

DISTNAME=	lz4-0.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lz4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-lz4/python-lz4
COMMENT=	Python LZ4 binding
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-deprecation-[0-9]*:../../devel/py-deprecation
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

.include "../../archivers/lz4/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
