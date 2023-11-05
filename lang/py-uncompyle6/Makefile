# $NetBSD: Makefile,v 1.33 2023/11/05 11:49:51 wiz Exp $

DISTNAME=	uncompyle6-3.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncompyle6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-uncompyle6
COMMENT=	Python cross-version byte-code decompiler
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-spark-parser>=1.8.9:../../lang/py-spark-parser
DEPENDS+=	${PYPKGPREFIX}-xdis>=6.0.2:../../devel/py-xdis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-xdis
# no support for python 3.11 or 3.12 yet
# https://github.com/rocky/python-uncompyle6/issues/423
PYTHON_VERSIONS_INCOMPATIBLE+=	311 312

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pydisassemble pydisassemble-${PYVERSSUFFIX} && \
	${MV} uncompyle6 uncompyle6-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/pytest && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
