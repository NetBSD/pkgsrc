# $NetBSD: Makefile,v 1.1.1.1 2003/05/19 18:42:09 hubertf Exp $
#

DISTNAME=	pyslsk-1.2.0
CATEGORIES=	net audio x11
MASTER_SITES=	http://www.sensi.org/~ak/pyslsk/

MAINTAINER=	hubertf@netbsd.org
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
