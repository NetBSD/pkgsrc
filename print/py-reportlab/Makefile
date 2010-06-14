# $NetBSD: Makefile,v 1.39 2010/06/14 08:51:36 joerg Exp $
#

DISTNAME=	ReportLab_2_4
PKGNAME=	${PYPKGPREFIX}-reportlab-2.4
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
