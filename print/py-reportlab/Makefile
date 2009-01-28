# $NetBSD: Makefile,v 1.32 2009/01/28 14:42:28 joerg Exp $
#

DISTNAME=	ReportLab_2_2
PKGNAME=	${PYPKGPREFIX}-reportlab-2.2
CATEGORIES=	print python
MASTER_SITES=	ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
