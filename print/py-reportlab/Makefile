# $NetBSD: Makefile,v 1.19 2004/05/05 09:06:35 drochner Exp $
#

DISTNAME=	ReportLab_1_19
PKGNAME=	${PYPKGPREFIX}-reportlab-1.19
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

WRKSRC=		${WRKDIR}/reportlab-1_19/reportlab/lib
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

post-install:
	cd ${WRKDIR}/reportlab-1_19 && \
		${PAX} -rw -pp reportlab ${PREFIX}/${PYSITELIB}
	${RM} -rf ${PREFIX}/${PYSITELIB}/reportlab/lib/build

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
