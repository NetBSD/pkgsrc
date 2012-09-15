# $NetBSD: Makefile,v 1.11 2012/09/15 10:04:07 obache Exp $
#
# Attention: Update this only together with devel/dconf-editor
#

DISTNAME=	dconf-0.12.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf/0.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/dconf
COMMENT=	Backend for gsettings
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --disable-editor
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	client/dconf.pc.in dbus-1/dconf-dbus-1.pc.in

BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala016/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
