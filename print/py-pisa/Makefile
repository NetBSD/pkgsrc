# $NetBSD: Makefile,v 1.6 2010/02/10 15:30:27 joerg Exp $
#

DISTNAME=	pisa-3.0.32
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc print www python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pisa/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.htmltopdf.org/
COMMENT=	HTML2pdf converter

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-reportlab>=2.2:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
