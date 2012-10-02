# $NetBSD: Makefile,v 1.22 2012/10/02 17:11:43 tron Exp $
#

DISTNAME=	swfdec-gnome-2.28.0
PKGREVISION=	17
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/swfdec-gnome/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swfdec.freedesktop.org/
COMMENT=	Gnome flash player and thumbnailer using swfdec

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

GCONF_SCHEMAS=		swfdec-thumbnailer.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/swfdec/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
