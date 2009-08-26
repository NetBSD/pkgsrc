# $NetBSD: Makefile,v 1.4 2009/08/26 19:58:07 sno Exp $
#

DISTNAME=	swfdec-gnome-2.26.0
PKGREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/swfdec-gnome/2.26/}
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
.include "../../mk/bsd.pkg.mk"
