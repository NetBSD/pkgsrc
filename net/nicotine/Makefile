# $NetBSD: Makefile,v 1.26 2008/04/25 20:39:11 joerg Exp $
#

DISTNAME=	nicotine-1.0.8
PKGREVISION=	5
CATEGORIES=	net audio x11
MASTER_SITES=	http://nicotine.thegraveyard.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nicotine.thegraveyard.org/
COMMENT=	Client for soulseek, a peer-to-peer network for music

USE_PKGLOCALEDIR=	yes

PYTHON_VERSIONS_ACCEPTED=	25 24
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
