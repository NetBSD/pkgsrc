# $NetBSD: Makefile,v 1.40 2010/10/15 20:23:35 joerg Exp $
#

DISTNAME=	reportlab-2.4
DISTFILES=	${DEFAULT_DISTFILES} pfbfer.zip
PKGNAME=	${PYPKGPREFIX}-reportlab-2.4
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/
SITES.pfbfer.zip=	http://www.reportlab.com/ftp/fonts/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ReportLab_2_4
EXTRACT_DIR.pfbfer.zip=	${WRKSRC}/src/reportlab/fonts

PYDISTUTILSPKG=	yes

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
