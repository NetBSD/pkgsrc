# $NetBSD: Makefile,v 1.23 2004/10/03 00:18:06 tv Exp $
#

DISTNAME=	ReportLab_1_19
PKGNAME=	${PYPKGPREFIX}-reportlab-1.19
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

BUILD_DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base

WRKSRC=		${WRKDIR}/reportlab-1_19/reportlab/lib
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

GTAR=		gtar

post-install:
	cd ${WRKDIR}/reportlab-1_19 && \
		${PAX} -rw -pp reportlab ${PREFIX}/${PYSITELIB}
	${RM} -rf ${PREFIX}/${PYSITELIB}/reportlab/lib/build

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
