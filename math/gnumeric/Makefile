# $NetBSD: Makefile,v 1.89 2004/10/03 00:12:56 tv Exp $
#

DISTNAME=		gnumeric-1.2.13
PKGREVISION=		1
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/1.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/gnumeric/
COMMENT=		Spreadsheet program from the GNOME project

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-python=python2p3
PYTHON_VERSION_REQD=	23pth
GCONF2_SCHEMAS=		gnumeric-dialogs.schemas gnumeric-general.schemas \
			gnumeric-plugins.schemas

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
# guile is currently not supported in gnumeric
#.include "../../lang/guile/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"

.include "../../mk/bsd.pkg.mk"
