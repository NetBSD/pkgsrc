# $NetBSD: Makefile,v 1.13 2003/07/26 15:00:58 drochner Exp $
#

DISTNAME=	ReportLab_1_18
PKGNAME=	${PYPKGPREFIX}-reportlab-1.18
WRKSRC=		${WRKDIR}/reportlab/lib
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

PYBINMODULE= yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

post-install:
	cd ${WRKDIR} && ${PAX} -rw -pp reportlab ${PREFIX}/${PYSITELIB}
	${RM} -rf ${PREFIX}/${PYSITELIB}/reportlab/lib/build

.include "../../textproc/pyxml/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
