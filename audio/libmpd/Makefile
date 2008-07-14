# $NetBSD: Makefile,v 1.6 2008/07/14 12:55:57 joerg Exp $
#

DISTNAME=		libmpd-0.15.0
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/gmpc-0.15.5/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cms.qballcow.nl/index.php?page=libmpd
COMMENT=		Library to access mpd (musicpd)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libmpd.pc.in
USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
