# $NetBSD: Makefile,v 1.1.1.1 2003/09/08 00:33:18 hubertf Exp $
#

DISTNAME=	nicotine-1.0.3
CATEGORIES=	net audio x11
MASTER_SITES=	http://nicotine.thegraveyard.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://nicotine.thegraveyard.org/
COMMENT=	Client for soulseek, a peer-to-peer network for music

NO_CONFIGURE=   yes
NO_BUILD=       yes
PYTHON_VERSIONS_ACCEPTED=       22pth 23pth
USE_BUILDLINK2=	yes

do-install:
	cd ${WRKSRC} ; \
	${PYTHONBIN} setup.py install --prefix=${PREFIX}

.include "../../lang/python22-pth/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
