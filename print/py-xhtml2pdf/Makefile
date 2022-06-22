# $NetBSD: Makefile,v 1.4 2022/06/22 01:26:35 joerg Exp $

DISTNAME=	xhtml2pdf-0.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xhtml2pdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xhtml2pdf/xhtml2pdf
COMMENT=	PDF generator using HTML and CSS
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-PDF2-[0-9]*:../../print/py-PDF2
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-arabic-reshaper>=2.1.0:../../converters/py-arabic-reshaper
DEPENDS+=	${PYPKGPREFIX}-bidi>=0.4.2:../../converters/py-bidi
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.0:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-reportlab>=3.3.0:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none
USE_PKG_RESOURCES=	yes

post-install:
.for bin in pisa xhtml2pdf
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
