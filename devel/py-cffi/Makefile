# $NetBSD: Makefile,v 1.34 2018/07/29 10:48:14 leot Exp $

DISTNAME=	cffi-1.11.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cffi.readthedocs.io/en/latest/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

#
# XXX: Kludge to avoid __thread that at the moment is still not properly
# XXX: supported on NetBSD/evbarm aarch64.
#
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "aarch64"
BUILDLINK_TRANSFORM+=	rm:-DUSE__THREAD
.endif

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

TEST_ENV+=	TMPDIR=${WRKDIR}/tmp

do-test:
	${MKDIR} ${WRKDIR}/tmp
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
