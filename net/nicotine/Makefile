# $NetBSD: Makefile,v 1.11 2004/03/26 02:27:48 wiz Exp $
#

DISTNAME=	nicotine-1.0.7
PKGREVISION=	2
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
