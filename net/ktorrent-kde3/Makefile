# $NetBSD: Makefile,v 1.1.1.1 2010/03/20 21:52:23 wiz Exp $

DISTNAME=	ktorrent-${KTORRENT_VER}
PKGREVISION=	4
CATEGORIES=	net kde
MASTER_SITES=	http://ktorrent.org/downloads/${KTORRENT_VER}/
EXTRACT_SUFX=	.tar.bz2

KTORRENT_VER=	2.2.8

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://ktorrent.org/
COMMENT=	Graphical BitTorrent client for KDE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt pkg-config bash:run perl:run
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

REPLACE_BASH=	scripts/ktshell

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
