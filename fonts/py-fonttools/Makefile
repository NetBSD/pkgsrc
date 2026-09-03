# $NetBSD: Makefile,v 1.134 2026/09/03 07:02:00 adam Exp $

DISTNAME=	fonttools-4.64.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	fonts python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FontTools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fonttools/fonttools
COMMENT=	Library for manipulating fonts
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.0:../../textproc/py-lxml
# woff
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.0.1:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-zopfli>=0.1.4:../../archivers/py-zopfli

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

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
