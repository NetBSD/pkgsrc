# $NetBSD: Makefile,v 1.22 2015/01/08 21:10:05 wiz Exp $

DISTNAME=	gnumeric-1.12.9
PKGREVISION=	2
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/1.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnumeric.org/
COMMENT=	Spreadsheet program from the GNOME project
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libspreadsheet.pc.in

REPLACE_PERL+=		plugins/perl-func/perl_func.pl

# PLIST contains versioned directory
GOFFICE_VERSION=	0.10.0
PLIST_SUBST+=		GOFFICE_VERSION=${GOFFICE_VERSION}

.include "options.mk"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.12.9
.include "../../lang/python/application.mk"
.include "../../devel/py-gobject3/buildlink3.mk"

#CONFIGURE_ARGS+=	--with-gnome

.include "../../devel/glib2/schemas.mk"
# XXX: that version's not in pkgsrc yet
#BUILDLINK_API_DEPENDS.libgda+=	libgda>=3.1.1
#.include "../../databases/libgda/buildlink3.mk"
#.include "../../databases/libgnomedb/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgsf+=	libgsf>=1.14.18
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
BUILDLINK_API_DEPENDS.goffice0.10+= goffice0.10>=0.10.9
.include "../../misc/goffice0.10/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
