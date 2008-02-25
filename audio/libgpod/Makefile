# $NetBSD: Makefile,v 1.6 2008/02/25 22:11:59 heinz Exp $

DISTNAME=		libgpod-0.6.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=		srp@tworoads.net
HOMEPAGE=		http://www.gtkpod.org/libgpod.html
COMMENT=		Library for accessing iPod onboard databases, playlists, etc

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
