# $NetBSD: Makefile,v 1.1.1.1 2009/01/28 14:45:44 joerg Exp $
#

DISTNAME=	pisa-3.0.29
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc print www python
MASTER_SITES=	http://pypi.pytho.org/pypi/pisa/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.htmltopdf.org/
COMMENT=	HTML2pdf converter

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-reportlab>=2.2:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
