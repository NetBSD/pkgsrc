# $NetBSD: Makefile,v 1.99 2014/01/01 11:52:28 wiz Exp $
#

DISTNAME=		bug-buddy-2.26.0
PKGREVISION=		31
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/bug-buddy/2.26/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Graphical GNOME2 bug reporting tool

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_TOOLS+=		autoconf
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
CPPFLAGS+=	-I${LOCALBASE}/include/libelf

GCONF_SCHEMAS=		bug-buddy.schemas

pre-configure:
	cd ${WRKSRC} && autoconf -f

.include "options.mk"

.include "../../mk/omf-scrollkeeper.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-settings-daemon/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.14.2
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
