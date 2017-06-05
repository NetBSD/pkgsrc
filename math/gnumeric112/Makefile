# $NetBSD: Makefile,v 1.34 2017/06/05 14:24:09 ryoon Exp $

DISTNAME=	gnumeric-1.12.23
PKGREVISION=	5
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/1.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnumeric.org/
COMMENT=	Spreadsheet program from the GNOME project
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libspreadsheet.pc.in

REPLACE_PERL+=		plugins/perl-func/perl_func.pl

# PLIST contains versioned directory
#GOFFICE_VERSION=	0.10.0
#PLIST_SUBST+=		GOFFICE_VERSION=${GOFFICE_VERSION}

.include "options.mk"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.12.9
.include "../../lang/python/application.mk"
.include "../../devel/py-gobject3/buildlink3.mk"

#CONFIGURE_ARGS+=	--with-gnome

.include "../../devel/glib2/schemas.mk"
# XXX: that version's not in pkgsrc yet
#BUILDLINK_API_DEPENDS.libgda+=	libgda>=3.1.1
#.include "../../databases/libgda/buildlink3.mk"
#.include "../../databases/libgnomedb/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgsf+=	libgsf>=1.14.32
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
BUILDLINK_API_DEPENDS.goffice0.10+= goffice0.10>=0.10.23
.include "../../misc/goffice0.10/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.4.12
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.8.7
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
