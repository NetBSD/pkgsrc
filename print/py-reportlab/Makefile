# $NetBSD: Makefile,v 1.7 2002/10/23 18:05:23 drochner Exp $
#

DISTNAME=	ReportLab_1_15
PKGNAME=	${PYPKGPREFIX}-reportlab-1.15
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	powerful PDF-generating toolkit for Python

WRKSRC=		${WRKDIR}/reportlab/lib

PYBINMODULE= yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

post-install:
	(cd ${WRKDIR}; ${PAX} -r -w -v -p p reportlab ${PREFIX}/${PYSITELIB})
	${RM} -rf ${PREFIX}/${PYSITELIB}/reportlab/lib/build

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
