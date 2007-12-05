# $NetBSD: Makefile,v 1.14 2007/12/05 11:05:24 abs Exp $

DISTNAME=	ktorrent-${KTORRENT_VER}
CATEGORIES=	net kde
MASTER_SITES=	http://ktorrent.org/downloads/${KTORRENT_VER}/

KTORRENT_VER=	2.2.4

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://ktorrent.org/
COMMENT=	Graphical BitTorrent client for KDE

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt pkg-config bash:run perl:run
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

REPLACE_BASH=	scripts/ktshell

BUILDLINK_DEPMETHOD.libXt?=	build

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
