# $NetBSD: Makefile,v 1.3 2003/07/17 22:51:44 grant Exp $
#

DISTNAME=	pyslsk-1.2.0
PKGREVISION=	1
CATEGORIES=	net audio x11
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.sensi.org/~ak/pyslsk/
COMMENT=	Python based Soulseek client

#DEPENDS+=	py22pth-wxWindows-*:../../x11/py-wxWindows

NO_CONFIGURE=	yes
NO_BUILD=	yes
PYTHON_VERSIONS_ACCEPTED=	22pth

do-install:
		cd ${WRKSRC} ; \
		${PYTHONBIN} setup.py install --prefix=${PREFIX}

.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
