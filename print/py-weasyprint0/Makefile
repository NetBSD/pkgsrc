# $NetBSD: Makefile,v 1.15 2023/11/05 13:42:01 wiz Exp $

DISTNAME=	WeasyPrint-0.42.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WeasyPrint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://weasyprint.org/
COMMENT=	Converts HTML/CSS documents to PDF (Python 2.x version)
LICENSE=	modified-bsd

DEPENDS+=	pango-[0-9]*:../../devel/pango
DEPENDS+=	${PYPKGPREFIX}-cairosvg>=1.0.20<2:../../converters/py27-cairosvg
DEPENDS+=	${PYPKGPREFIX}-cairocffi>=0.5:../../graphics/py-cairocffi
DEPENDS+=	${PYPKGPREFIX}-cffi>=0.6:../../devel/py27-cffi
DEPENDS+=	${PYPKGPREFIX}-cssselect2>=0.1:../../textproc/py27-cssselect2
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999999999:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-pdfrw>=0.4:../../textproc/py-pdfrw
DEPENDS+=	${PYPKGPREFIX}-pyphen>=0.8:../../textproc/py27-pyphen
DEPENDS+=	${PYPKGPREFIX}-tinycss2>=0.5:../../textproc/py27-tinycss2
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py27-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
