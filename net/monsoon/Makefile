# $NetBSD: Makefile,v 1.25 2012/09/15 10:06:05 obache Exp $

DISTNAME=	monsoon-0.20
PKGREVISION=	20
CATEGORIES=	net
MASTER_SITES=	http://www.monsoon-project.org/jaws/data/files/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.monsoon-project.org/
COMMENT=	Open source GTK+ bittorrent client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake gtar intltool perl pkg-config msgfmt
EXTRACT_USING=	gtar

.include "../../lang/mono/buildlink3.mk"
.include "../../net/mono-nat/buildlink3.mk"
.include "../../net/monotorrent/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
