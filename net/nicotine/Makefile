# $NetBSD: Makefile,v 1.8 2004/02/16 19:40:39 hubertf Exp $
#

DISTNAME=	nicotine-1.0.7
CATEGORIES=	net audio x11
MASTER_SITES=	http://nicotine.thegraveyard.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://nicotine.thegraveyard.org/
COMMENT=	Client for soulseek, a peer-to-peer network for music

PYTHON_VERSIONS_ACCEPTED=       22pth 23pth
USE_BUILDLINK2=	yes
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
