# $NetBSD: Makefile,v 1.6 2004/07/22 09:16:04 recht Exp $
#

DISTNAME=	renderPM-0-9
PKGNAME=	${PYPKGPREFIX}-reportlab-renderPM-0.9
CATEGORIES=	print python
MASTER_SITES=   http://www.reportlab.com/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/rl_addons.html
COMMENT=	Pixmap rendering for reportlab

WRKSRC=		${WRKDIR}
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
