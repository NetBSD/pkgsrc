# $NetBSD: Makefile,v 1.11 2007/02/22 19:27:06 wiz Exp $
#

DISTNAME=	renderPM-0-9
PKGNAME=	${PYPKGPREFIX}-reportlab-renderPM-0.9
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/rl_addons.html
COMMENT=	Pixmap rendering for reportlab

WRKSRC=		${WRKDIR}
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
