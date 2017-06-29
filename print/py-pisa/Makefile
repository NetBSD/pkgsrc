# $NetBSD: Makefile,v 1.18 2017/06/29 20:02:02 joerg Exp $

DISTNAME=	pisa-3.0.33
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc print www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pisa/}

OWNER=		joerg@NetBSD.org
HOMEPAGE=	http://www.htmltopdf.org/
COMMENT=	HTML2pdf converter (obsolete, use print/py-weasyprint instead)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-reportlab>=2.2:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not ported as of 3.0.33

# remove CRs: fixes patching on Darwin and stops pkglint from complaining
pre-patch:
.for f in css.py cssDOMElementInterface.py
	${TR} -d '\r' < ${WRKSRC}/sx/w3c/${f} > ${WRKSRC}/sx/w3c/${f}.new
	${MV} ${WRKSRC}/sx/w3c/${f}.new ${WRKSRC}/sx/w3c/${f}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
