# $NetBSD: Makefile,v 1.10 2026/09/03 06:44:48 adam Exp $

DISTNAME=	xhtml2pdf-0.2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xhtml2pdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xhtml2pdf/xhtml2pdf
COMMENT=	PDF generator using HTML and CSS
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.1.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-arabic-reshaper>=3.0.0:../../converters/py-arabic-reshaper
DEPENDS+=	${PYPKGPREFIX}-asn1crypto>=0:../../security/py-asn1crypto
DEPENDS+=	${PYPKGPREFIX}-bidi>=0.5.0:../../converters/py-bidi
DEPENDS+=	${PYPKGPREFIX}-hanko>=0.12.1:../../security/py-hanko
DEPENDS+=	${PYPKGPREFIX}-hanko-certvalidator>=0.19.5:../../security/py-hanko-certvalidator
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-pdf>=3.1.0:../../textproc/py-pdf
DEPENDS+=	${PYPKGPREFIX}-reportlab>=4.0.4:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-svglib>=1.2.1:../../graphics/py-svglib

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pisa xhtml2pdf

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
