# $NetBSD: Makefile,v 1.1.1.1 2007/05/05 21:34:07 wiz Exp $
#

DISTNAME=		gnumeric-1.7.10
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/1.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/gnumeric/
COMMENT=		Spreadsheet program from the GNOME project (development version)

USE_DIRS+=		gnome2-1.6 xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
GCONF2_SCHEMAS=		gnumeric-dialogs.schemas gnumeric-general.schemas \
			gnumeric-plugins.schemas
PKGCONFIG_OVERRIDE=	libspreadsheet-1.7.pc.in

# XXX: link test against libpython fails
#CONFIGURE_ARGS+=	--with-python
#CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
#PYTHON_VERSIONS_ACCEPTED=	24 23
#.include "../../lang/python/application.mk"
#.include "../../x11/py-gtk2/buildlink3.mk"

BUILDLINK_API_DEPENDS.libgda+=	libgda>=1.9.103
.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgsf+=	libgsf>=1.14.2
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../misc/goffice/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
