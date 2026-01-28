# $NetBSD: Makefile,v 1.8 2026/01/28 10:33:30 wiz Exp $

DISTNAME=	xhtml2pdf-0.2.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xhtml2pdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xhtml2pdf/xhtml2pdf
COMMENT=	PDF generator using HTML and CSS
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pdf>=3.1.0:../../textproc/py-pdf
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.1.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-arabic-reshaper>=3.0.0:../../converters/py-arabic-reshaper
DEPENDS+=	${PYPKGPREFIX}-bidi>=0.5.0:../../converters/py-bidi
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-svglib>=1.2.1:../../graphics/py-svglib
DEPENDS+=	${PYPKGPREFIX}-reportlab>=4.0.4:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-asn1crypto-[0-9]*:../../security/py-asn1crypto
DEPENDS+=	${PYPKGPREFIX}-hanko>=0.12.1:../../security/py-hanko
DEPENDS+=	${PYPKGPREFIX}-hanko-certvalidator>=0.19.5:../../security/py-hanko-certvalidator

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
.for bin in pisa xhtml2pdf
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
