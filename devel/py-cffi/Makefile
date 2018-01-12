# $NetBSD: Makefile,v 1.31 2018/01/12 12:26:00 adam Exp $

DISTNAME=	cffi-1.11.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cffi/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

TEST_ENV+=	TMPDIR=${WRKDIR}/tmp

do-test:
	${MKDIR} ${WRKDIR}/tmp
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${TEST_ENV} ${PREFIX}/bin/py.test-${PYVERSSUFFIX}

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
