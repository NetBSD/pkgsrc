# $NetBSD: Makefile,v 1.38 2004/10/11 08:08:56 jmmv Exp $
#

DISTNAME=		gedit-2.8.1
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gedit/2.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gedit.sourceforge.net/
COMMENT=		Lightweight GNOME2 text editor

BUILD_USES_MSGFMT=	YES

USE_PERL5=		build
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE+=	data/gedit.pc.in

GCONF2_SCHEMAS=		gedit.schemas

CONFIGURE_ARGS+=	--enable-schemas-install

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
