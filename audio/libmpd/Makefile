# $NetBSD: Makefile,v 1.8 2009/05/30 00:44:59 obache Exp $
#

DISTNAME=		libmpd-0.18.0
CATEGORIES=		audio
#MASTER_SITES=		http://download.qballcow.nl/gmpc-0.15.5/
MASTER_SITES=		http://download.sarine.nl/Programs/gmpc/0.18.0/ \
			${MASTER_SITE_SOURCEFORGE:=musicpd/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gmpc.wikia.com/?title=Libmpd
COMMENT=		Library to access mpd (musicpd)
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libmpd.pc.in
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
