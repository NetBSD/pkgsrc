# $NetBSD: Makefile,v 1.120 2007/05/05 00:18:59 wiz Exp $
#

DISTNAME=		gnumeric-1.6.3
PKGREVISION=		6
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/1.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/gnumeric/
COMMENT=		Spreadsheet program from the GNOME project

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYTHON_VERSIONS_ACCEPTED=	24 23
GCONF2_SCHEMAS=		gnumeric-dialogs.schemas gnumeric-general.schemas \
			gnumeric-plugins.schemas

# XXX: link test against libDynaLoader_pic.a fails; bug
# in buildlink
PLIST_SUBST+=	PERL="@comment "
#.include "../../lang/perl5/buildlink3.mk"

BUILDLINK_API_DEPENDS.libgda+=	libgda>=1.9.103
.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
# guile is currently not supported in gnumeric
#.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../misc/goffice0.2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeprint+=	libgnomeprint>=2.8.2
.include "../../print/libgnomeprint/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeprintui+=	libgnomeprintui>=2.8.2
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
# XXX: link test against libpython fails
#.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
