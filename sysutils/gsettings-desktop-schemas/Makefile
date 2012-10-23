# $NetBSD: Makefile,v 1.3 2012/10/23 19:51:06 asau Exp $
#

DISTNAME=	gsettings-desktop-schemas-3.4.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gsettings-desktop-schemas/3.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Collection of GSettings schemas for the GNOME desktop
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
# Necessary because of configure test
USE_LANGUAGES=		c

PKGCONFIG_OVERRIDE+=	gsettings-desktop-schemas.pc.in

.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
