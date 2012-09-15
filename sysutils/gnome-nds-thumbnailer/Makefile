# $NetBSD: Makefile,v 1.15 2012/09/15 10:06:24 obache Exp $
#

DISTNAME=	gnome-nds-thumbnailer-1.2.1
PKGREVISION=	12
CATEGORIES=	sysutils graphics emulators
MASTER_SITES=	http://download.gnome.org/sources/gnome-nds-thumbnailer/1.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.gnome.org/sources/gnome-nds-thumbnailer/1.2/
COMMENT=	Thumbnailer for GNOME for Nintendo DS ROMs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

GCONF_SCHEMAS+=	gnome-nds-thumbnailer.schemas

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
