# $NetBSD: Makefile,v 1.27 2017/07/03 18:17:45 joerg Exp $

DISTNAME=	cffi-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cffi/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

USE_LANGUAGES=	c

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
USE_LANGUAGES+=	c++
.endif

TEST_ENV+=	TMPDIR=${WRKDIR}/tmp

do-test:
	${MKDIR} ${WRKDIR}/tmp
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${TEST_ENV} ${PREFIX}/bin/py.test-${PYVERSSUFFIX} -v

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
