# $NetBSD: Makefile,v 1.12 2004/10/03 00:17:57 tv Exp $
#

DISTNAME=	pyslsk-1.2.4
PKGREVISION=	5
CATEGORIES=	net audio x11
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.sensi.org/~ak/pyslsk/
COMMENT=	Python based Soulseek client

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED= 23pth 22pth
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWindows/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
