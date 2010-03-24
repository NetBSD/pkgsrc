# $NetBSD: Makefile,v 1.141 2010/03/24 19:43:23 asau Exp $
#

DISTNAME=		gnucash-2.2.9
PKGREVISION=		6
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal or business finance management program
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		guile-slib>=3.2.1:../../devel/guile-slib
DEPENDS+=		guile-www>=2.21:../../devel/guile-www
DEPENDS+=		p5-Finance-Quote-[0-9]*:../../finance/p5-Finance-Quote
DEPENDS+=		p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool makeinfo msgfmt perl:run pkg-config
GNU_CONFIGURE=		yes
INFO_FILES=		YES

REPLACE_PERL+=		src/quotes/gnc-fq-dump
REPLACE_PERL+=		src/optional/xsl/vcard-gnccustomer.pl

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF_SCHEMAS+=	apps_gnucash_history.schemas
GCONF_SCHEMAS+=	apps_gnucash_dialog_commodities.schemas
GCONF_SCHEMAS+=	apps_gnucash_dialog_common.schemas
GCONF_SCHEMAS+=	apps_gnucash_dialog_print_checks.schemas
GCONF_SCHEMAS+=	apps_gnucash_dialog_prices.schemas
GCONF_SCHEMAS+=	apps_gnucash_warnings.schemas
GCONF_SCHEMAS+=	apps_gnucash_dialog_reconcile.schemas
GCONF_SCHEMAS+=	apps_gnucash_dialog_totd.schemas
GCONF_SCHEMAS+=	apps_gnucash_general.schemas
GCONF_SCHEMAS+=	apps_gnucash_window_pages_account_tree.schemas
GCONF_SCHEMAS+=	apps_gnucash_window_pages_register.schemas
GCONF_SCHEMAS+=	apps_gnucash_import_generic_matcher.schemas
#GCONF_SCHEMAS+=	apps_gnucash_dialog_hbci.schemas
GCONF_SCHEMAS+=	apps_gnucash_dialog_business_common.schemas

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
#BUILDLINK_API_DEPENDS.swig+=	swig>=1.3.28
#.include "../../devel/swig/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.8.0
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../finance/libofx/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../misc/goffice0.6/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeprint+=	libgnomeprint>=2.10.0
.include "../../print/libgnomeprint/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeprintui+=	libgnomeprintui>=2.10.0
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.3
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
