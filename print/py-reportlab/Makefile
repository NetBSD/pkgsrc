# $NetBSD: Makefile,v 1.9 2003/03/29 12:42:17 jmmv Exp $
#

DISTNAME=	ReportLab_1_16
PKGNAME=	${PYPKGPREFIX}-reportlab-1.16
WRKSRC=		${WRKDIR}/reportlab/lib
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	powerful PDF-generating toolkit for Python

PYBINMODULE= yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

post-install:
	(cd ${WRKDIR}; ${PAX} -r -w -v -p p reportlab ${PREFIX}/${PYSITELIB})
	${RM} -rf ${PREFIX}/${PYSITELIB}/reportlab/lib/build

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
