# $NetBSD: Makefile,v 1.8 2022/11/30 17:02:32 adam Exp $

DISTNAME=	ofxparse-0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/ofxparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sites.google.com/site/ofxparse
COMMENT=	Tools for working with the OFX file format
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-beautifulsoup4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
