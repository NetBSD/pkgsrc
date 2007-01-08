# $NetBSD: Makefile,v 1.3 2007/01/08 22:10:38 xtraeme Exp $

DISTNAME=	ktorrent-${KTORRENT_VER}
PKGREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	http://ktorrent.org/downloads/${KTORRENT_VER}/

KTORRENT_VER=	2.1beta1

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://ktorrent.org/
COMMENT=	Graphical BitTorrent client for KDE

USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt perl:run
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
