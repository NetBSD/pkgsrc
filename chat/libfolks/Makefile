# $NetBSD: Makefile,v 1.8 2012/09/15 10:03:51 obache Exp $
#

DISTNAME=	folks-0.4.2
PKGNAME=	lib${DISTNAME}
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/folks/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Folks
COMMENT=	Library to manage contacts
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt
USE_PKGLOCALEDIR= yes

PKGCONFIG_OVERRIDE+=	backends/telepathy/lib/folks-telepathy.pc.in
PKGCONFIG_OVERRIDE+=	folks/folks.pc.in

TEST_TARGET=	check

CPPFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
