# $NetBSD: Makefile,v 1.4 2009/05/13 08:27:49 hasso Exp $
#

DISTNAME=	pisa-3.0.29
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc print www python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pisa/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.htmltopdf.org/
COMMENT=	HTML2pdf converter

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-reportlab>=2.2:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

PYTHON_VERSIONS_ACCEPTED=	25 24

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
