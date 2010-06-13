# $NetBSD: Makefile,v 1.11 2010/06/13 22:43:50 wiz Exp $

DISTNAME=		libgpod-0.7.0
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=		srp@tworoads.net
HOMEPAGE=		http://www.gtkpod.org/libgpod/
COMMENT=		Library for accessing iPod onboard databases, playlists, etc

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE=	libgpod-1.0.pc.in

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
