# $NetBSD: Makefile,v 1.118 2026/09/02 19:03:23 wiz Exp $

DISTNAME=	gnumeric-1.12.61
PKGREVISION=	3
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/1.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gnome.pages.gitlab.gnome.org/gnumeric-web//
COMMENT=	Spreadsheet program from the GNOME project
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config yacc
USE_TOOLS+=		itstool
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libspreadsheet.pc.in

REPLACE_PERL+=		doc/make-func-list.pl
REPLACE_PERL+=		plugins/perl-func/perl_func.pl
REPLACE_PERL+=		plugins/perl-loader/perl-cc-wrapper
REPLACE_PERL+=		test/*.pl
REPLACE_PERL+=		test/normalize-gnumeric
REPLACE_PERL+=		tools/biffnames
REPLACE_PERL+=		tools/check-gfrees
REPLACE_PERL+=		tools/check-glade-parsing
REPLACE_PERL+=		tools/check-gtk-includes
REPLACE_PERL+=		tools/check-null-false-returns
REPLACE_PERL+=		tools/dumpdef.pl
REPLACE_PERL+=		tools/embedder
REPLACE_PERL+=		tools/gnmgdb
REPLACE_PERL+=		tools/gnmvalgrind
REPLACE_PERL+=		tools/handle-conf-options
REPLACE_PERL+=		tools/itstoolwrapper

# needs a DISPLAY
TEST_TARGET=		check

.include "options.mk"

CONFIGURE_ENV+=			PYTHON=${PYTHONBIN:Q}

.include "../../devel/glib2/schemas.mk"
# also needs libgda-ui, currently not in pkgsrc
#BUILDLINK_API_DEPENDS.libgda+=	libgda>=5.0
#.include "../../databases/libgda/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgsf+=	libgsf>=1.14.33
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
BUILDLINK_API_DEPENDS.goffice0.10+= goffice0.10>=0.10.61
.include "../../misc/goffice0.10/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.20
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
