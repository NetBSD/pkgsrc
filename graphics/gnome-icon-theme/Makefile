# $NetBSD: Makefile,v 1.43 2006/11/28 22:24:03 drochner Exp $
#

DISTNAME=		gnome-icon-theme-2.16.1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/2.16/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Theme consisting of a set of icons for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	gnome-icon-theme.pc.in

BUILDLINK_API_DEPENDS.hicolor-icon-theme+=	hicolor-icon-theme>=0.5
HICOLOR_ICON_THEME_DEPEND_ONLY=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
