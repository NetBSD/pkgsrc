# $NetBSD: Makefile,v 1.7 2009/01/20 22:41:03 drochner Exp $
#

DISTNAME=		libmpd-0.17.0
CATEGORIES=		audio
#MASTER_SITES=		http://download.qballcow.nl/gmpc-0.15.5/
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}

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
