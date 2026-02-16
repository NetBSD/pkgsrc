# $NetBSD: Makefile,v 1.93 2026/02/16 11:29:23 adam Exp $

DISTNAME=	reportlab-4.4.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reportlab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer-[0-9]*:../../converters/py-charset-normalizer

USE_LANGUAGES=	# none

# The files should already be included in the distfile.
WHEEL_ARGS+=	-C=--no-download-t1-files

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
