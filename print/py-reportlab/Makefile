# $NetBSD: Makefile,v 1.25 2005/04/11 21:47:09 tv Exp $
#

DISTNAME=	ReportLab_1_20
PKGNAME=	${PYPKGPREFIX}-reportlab-1.20
CATEGORIES=	print python
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

WRKSRC=		${WRKDIR}/reportlab_1_20/reportlab
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
