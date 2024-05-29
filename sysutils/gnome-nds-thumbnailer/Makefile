# $NetBSD: Makefile,v 1.53 2024/05/29 16:34:25 adam Exp $
#

DISTNAME=	gnome-nds-thumbnailer-1.2.1
PKGREVISION=	48
CATEGORIES=	sysutils graphics emulators
MASTER_SITES=	https://download.gnome.org/sources/gnome-nds-thumbnailer/1.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://download.gnome.org/sources/gnome-nds-thumbnailer/1.2/
COMMENT=	Thumbnailer for GNOME for Nintendo DS ROMs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

GCONF_SCHEMAS+=	gnome-nds-thumbnailer.schemas

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
