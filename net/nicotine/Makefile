# $NetBSD: Makefile,v 1.13 2005/01/04 00:39:43 hubertf Exp $
#

DISTNAME=	nicotine-1.0.8
CATEGORIES=	net audio x11
MASTER_SITES=	http://nicotine.thegraveyard.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://nicotine.thegraveyard.org/
COMMENT=	Client for soulseek, a peer-to-peer network for music

PYTHON_VERSIONS_ACCEPTED=       22pth 23pth
USE_BUILDLINK3=	yes
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
