# $NetBSD: Makefile,v 1.21.2.1 2012/10/03 12:07:29 spz Exp $
#

DISTNAME=	ghex-2.24.0
PKGREVISION=	18
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ghex/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Hex editor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake

PKGCONFIG_OVERRIDE+=	gtkhex.pc.in
GCONF_SCHEMAS=	ghex2.schemas

.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
