# $NetBSD: Makefile,v 1.15 2004/01/20 12:24:29 agc Exp $
#

DISTNAME=	ReportLab_1_18
PKGNAME=	${PYPKGPREFIX}-reportlab-1.18
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

WRKSRC=		${WRKDIR}/reportlab/lib
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

post-install:
	cd ${WRKDIR} && ${PAX} -rw -pp reportlab ${PREFIX}/${PYSITELIB}
	${RM} -rf ${PREFIX}/${PYSITELIB}/reportlab/lib/build

.include "../../lang/python/extension.mk"
.include "../../textproc/pyxml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
