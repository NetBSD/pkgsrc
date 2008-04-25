# $NetBSD: Makefile,v 1.30 2008/04/25 19:50:11 joerg Exp $
#

DISTNAME=	ReportLab_1_21_2
PKGNAME=	${PYPKGPREFIX}-reportlab-1.21.2
CATEGORIES=	print python
MASTER_SITES=	ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

PYTHON_VERSIONS_ACCEPTED=	25 24 23 21

WRKSRC=		${WRKDIR}/reportlab_1_21_2/reportlab
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
