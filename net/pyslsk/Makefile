# $NetBSD: Makefile,v 1.6 2003/09/21 09:17:02 jmc Exp $
#

DISTNAME=	pyslsk-1.2.4
CATEGORIES=	net audio x11
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.sensi.org/~ak/pyslsk/
COMMENT=	Python based Soulseek client

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED= 23pth 22pth
USE_BUILDLINK2=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
