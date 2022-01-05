# $NetBSD: Makefile,v 1.21 2022/01/05 15:40:58 wiz Exp $

DISTNAME=	CairoSVG-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	converters graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CairoSVG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cairosvg.org/
COMMENT=	Simple SVG Converter for Cairo
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cairocffi-[0-9]*:../../graphics/py-cairocffi
DEPENDS+=	${PYPKGPREFIX}-cssselect2-[0-9]*:../../textproc/py-cssselect2
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-tinycss2-[0-9]*:../../textproc/py-tinycss2
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cairosvg cairosvg-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
