# $NetBSD: Makefile,v 1.4 2004/01/20 12:24:29 agc Exp $
#

DISTNAME=	renderPM-0-9
PKGNAME=	${PYPKGPREFIX}-reportlab-renderPM-0.9
CATEGORIES=	print
MASTER_SITES=   http://www.reportlab.com/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/rl_addons.html
COMMENT=	Pixmap rendering for reportlab

WRKSRC=		${WRKDIR}
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
