# $NetBSD: Makefile,v 1.12 2008/04/25 19:50:11 joerg Exp $
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

PYTHON_VERSIONS_ACCEPTED=	25 24 23 21

WRKSRC=		${WRKDIR}
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
