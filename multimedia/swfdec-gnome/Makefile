# $NetBSD: Makefile,v 1.1.1.1 2008/10/31 12:46:27 wiz Exp $
#

DISTNAME=	swfdec-gnome-2.24.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/swfdec-gnome/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swfdec.freedesktop.org/
COMMENT=	Gnome flash player and thumbnailer using swfdec

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_DIRS+=		gnome2-1.5 xdg-1.4
USE_PKGLOCALEDIR=	YES

GCONF_SCHEMAS=		swfdec-thumbnailer.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/swfdec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
