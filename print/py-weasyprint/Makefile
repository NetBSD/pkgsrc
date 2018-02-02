# $NetBSD: Makefile,v 1.12 2018/02/02 10:40:11 adam Exp $

DISTNAME=	WeasyPrint-0.42.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WeasyPrint/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://weasyprint.org/
COMMENT=	Converts HTML/CSS documents to PDF
LICENSE=	modified-bsd

DEPENDS+=	pango-[0-9]*:../../devel/pango
DEPENDS+=	${PYPKGPREFIX}-cairosvg>=1.0.20:../../converters/py-cairosvg
DEPENDS+=	${PYPKGPREFIX}-cairocffi>=0.5:../../graphics/py-cairocffi
DEPENDS+=	${PYPKGPREFIX}-cffi>=0.6:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cssselect2>=0.1:../../textproc/py-cssselect2
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999999999:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-pdfrw>=0.4:../../textproc/py-pdfrw
DEPENDS+=	${PYPKGPREFIX}-pyphen>=0.8:../../textproc/py-pyphen
DEPENDS+=	${PYPKGPREFIX}-tinycss2>=0.5:../../textproc/py-tinycss2
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-isort
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
