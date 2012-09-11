# $NetBSD: Makefile,v 1.159 2012/09/11 23:04:20 asau Exp $
#

DISTNAME=		gnumeric-1.8.4
PKGREVISION=		23
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnumeric/1.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/gnumeric/
COMMENT=		Spreadsheet program from the GNOME project (development version)
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-gnome
PKGCONFIG_OVERRIDE=	libspreadsheet.pc.in

REPLACE_PERL+=		plugins/perl-func/perl_func.pl

.include "options.mk"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
.include "../../lang/python/application.mk"
.include "../../devel/py-gobject/buildlink3.mk"

# XXX: that version's not in pkgsrc yet
#BUILDLINK_API_DEPENDS.libgda+=	libgda>=3.1.1
#.include "../../databases/libgda/buildlink3.mk"
#.include "../../databases/libgnomedb/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgsf+=	libgsf>=1.14.6
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../misc/goffice0.6/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
