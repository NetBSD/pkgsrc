# $NetBSD: Makefile,v 1.49 2007/06/26 13:19:26 rillig Exp $
#

DISTNAME=		gnome-icon-theme-2.18.0
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/2.18/}
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

# XXX this is used by applications. We "own" the subtree share/icons/gnome,
# so we control the subdirs not belonging to a single application.
post-install:
	${MKDIR} ${PREFIX}/share/icons/gnome/48x48/mimetypes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
