# $NetBSD: Makefile,v 1.21 2018/07/03 05:03:30 adam Exp $

DISTNAME=	pisa-3.0.33
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc print www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pisa/}

OWNER=		joerg@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pisa/
COMMENT=	HTML2pdf converter (obsolete, use print/py-weasyprint instead)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-reportlab>=2.2:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not ported as of 3.0.33

# remove CRs: fixes patching on Darwin and stops pkglint from complaining
pre-patch:
	cd ${WRKSRC} && for f in sx/*/*.py; do \
		${TR} -d '\r' < $$f > $${f}.new && ${MV} $${f}.new $$f; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
