# $NetBSD: Makefile,v 1.132 2026/05/17 15:55:21 wiz Exp $

DISTNAME=	fonttools-4.63.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	fonts python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FontTools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fonttools/fonttools
COMMENT=	Library for manipulating fonts
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.0:../../textproc/py-lxml
# woff
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.0.1:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-zopfli>=0.1.4:../../archivers/py-zopfli
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	310

# as of 4.63.0
# https://github.com/fonttools/fonttools/issues/3660
# 8 failed, 4611 passed, 65 skipped, 2 xfailed, 29 warnings

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.
SUBST_FILES.man+=	setup.py
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"

PY_RENAME_BINARIES=	fonttools pyftmerge pyftsubset ttx

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
	${MV} ttx.1 ttx-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
