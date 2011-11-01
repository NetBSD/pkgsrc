# $NetBSD: Makefile,v 1.38 2011/11/01 06:02:22 sbd Exp $
#

DISTNAME=	nicotine-1.0.8
PKGREVISION=	14
CATEGORIES=	net audio x11
MASTER_SITES=	http://nicotine.thegraveyard.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nicotine.thegraveyard.org/
COMMENT=	Client for soulseek, a peer-to-peer network for music
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes

.include "../../lang/python/distutils.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
