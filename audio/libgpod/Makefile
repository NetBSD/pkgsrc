# $NetBSD: Makefile,v 1.3 2007/02/07 22:30:10 drochner Exp $

DISTNAME=		libgpod-0.4.2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkpod/}

MAINTAINER=		srp@tworoads.net
HOMEPAGE=		http://www.gtkpod.org/libgpod.html
COMMENT=		Library for accessing iPod onboard databases, playlists, etc.

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
