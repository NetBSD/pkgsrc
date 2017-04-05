# $NetBSD: Makefile,v 1.25 2017/04/05 15:54:26 wiz Exp $

DISTNAME=	cffi-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cffi/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

USE_TOOLS+=	pkg-config

DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# needs 'make install' before running the tests
# segfault in c/test_c.py::test_callback
# https://bitbucket.org/cffi/cffi/issues/303/cffi-191-segmentation-fault-during-self
# probably problem in libffi
do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX} -v

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
