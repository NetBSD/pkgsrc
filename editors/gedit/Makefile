# $NetBSD: Makefile,v 1.48 2005/06/10 09:21:42 jmmv Exp $
#

DISTNAME=		gedit-2.10.3
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gedit/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gedit.sourceforge.net/
COMMENT=		Lightweight GNOME2 text editor

BUILD_USES_MSGFMT=	YES

USE_PERL5=		build
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
USE_MSGFMT_PLURALS=	YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE+=	data/gedit.pc.in

GCONF2_SCHEMAS=		gedit.schemas

CONFIGURE_ARGS+=	--enable-schemas-install

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_DEPENDS.libglade2+=	libglade2>=2.4.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
