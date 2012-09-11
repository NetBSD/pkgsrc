# $NetBSD: Makefile,v 1.37 2012/09/11 23:04:21 asau Exp $

DISTNAME=	gnumeric-1.10.17
PKGREVISION=	6
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/1.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/gnumeric/
COMMENT=	Spreadsheet program from the GNOME project
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
GCONF_SCHEMAS=		gnumeric-dialogs.schemas gnumeric-general.schemas \
			gnumeric-plugins.schemas
PKGCONFIG_OVERRIDE=	libspreadsheet.pc.in

REPLACE_PERL+=		plugins/perl-func/perl_func.pl

# PLIST contains versioned directory
GOFFICE_VERSION=	0.8.17
PLIST_SUBST+=		GOFFICE_VERSION=${GOFFICE_VERSION}

.include "options.mk"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
.include "../../lang/python/application.mk"
.include "../../devel/py-gobject/buildlink3.mk"

#CONFIGURE_ARGS+=	--with-gnome

.include "../../devel/glib2/schemas.mk"
# XXX: that version's not in pkgsrc yet
#BUILDLINK_API_DEPENDS.libgda+=	libgda>=3.1.1
#.include "../../databases/libgda/buildlink3.mk"
#.include "../../databases/libgnomedb/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgsf+=	libgsf>=1.14.18
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
BUILDLINK_API_DEPENDS.goffice0.8+= goffice0.8-${GOFFICE_VERSION}{,nb*}
.include "../../misc/goffice0.8/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
