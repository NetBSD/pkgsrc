# $NetBSD: Makefile,v 1.10 2014/05/09 07:37:17 wiz Exp $

DISTNAME=	pisa-3.0.33
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc print www python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pisa/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.htmltopdf.org/
COMMENT=	HTML2pdf converter
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-reportlab>=2.2:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-reportlab

# remove CRs: fixes patching on Darwin and stops pkglint from complaining
pre-patch:
.for f in css.py cssDOMElementInterface.py
	${TR} -d '\r' < ${WRKSRC}/sx/w3c/${f} > ${WRKSRC}/sx/w3c/${f}.new
	${MV} ${WRKSRC}/sx/w3c/${f}.new ${WRKSRC}/sx/w3c/${f}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
