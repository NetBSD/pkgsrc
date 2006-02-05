# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:39 joerg Exp $
#

DISTNAME=	renderPM-0-9
PKGNAME=	${PYPKGPREFIX}-reportlab-renderPM-0.9
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=   http://www.reportlab.com/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/rl_addons.html
COMMENT=	Pixmap rendering for reportlab

WRKSRC=		${WRKDIR}
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
