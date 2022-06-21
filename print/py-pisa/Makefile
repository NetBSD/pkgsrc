# $NetBSD: Makefile,v 1.29 2022/06/21 22:18:16 joerg Exp $

DISTNAME=	pisa-3.0.33
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	print textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pisa/}

OWNER=		joerg@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pisa/
COMMENT=	HTML2pdf converter (obsolete, use print/py-weasyprint instead)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Pdf-[0-9]*:../../print/py-Pdf
DEPENDS+=	${PYPKGPREFIX}-reportlab>=2.2:../../print/py-reportlab
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

PYTHON_VERSIONS_ACCEPTED=	27 # not ported as of 3.0.33

USE_PKG_RESOURCES=	yes

# remove CRs: fixes patching on Darwin and stops pkglint from complaining
pre-patch:
	cd ${WRKSRC} && for f in sx/*/*.py; do \
		${TR} -d '\r' < $$f > $${f}.new && ${MV} $${f}.new $$f; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
