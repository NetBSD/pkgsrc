# $NetBSD: Makefile,v 1.24 2005/01/21 15:18:58 drochner Exp $
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
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
