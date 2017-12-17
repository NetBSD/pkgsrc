# $NetBSD: Makefile,v 1.59 2017/12/17 16:47:54 adam Exp $

DISTNAME=	reportlab-3.4.0
DISTFILES=	${DEFAULT_DISTFILES} pfbfer.zip
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/reportlab/}
SITES.pfbfer.zip=	http://www.reportlab.com/ftp/fonts/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.4.0:../../graphics/py-Pillow

EXTRACT_DIR.pfbfer.zip=	${WRKSRC}/src/reportlab/fonts
EXTRACT_OPTS_ZIP+=	-L

# fixup group/world writeable fonts from pfbfer.zip
post-install:
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${PYSITELIB}/reportlab/fonts/*.pfb

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py tests

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
