# $NetBSD: Makefile,v 1.173 2012/10/03 16:10:12 asau Exp $
#

DISTNAME=		gnucash-2.4.11
PKGREVISION=		4
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal or business finance management program
LICENSE=		gnu-gpl-v3

DEPENDS+=		guile-slib>=3.2.1:../../devel/guile-slib
DEPENDS+=		guile-www>=2.21:../../devel/guile-www
DEPENDS+=		p5-Finance-Quote-[0-9]*:../../finance/p5-Finance-Quote
DEPENDS+=		p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool makeinfo msgfmt perl:run pkg-config
GNU_CONFIGURE=		yes
INFO_FILES=		YES

CONFIGURE_ARGS+=	--with-html-engine=webkit
CONFIGURE_ARGS+=	--disable-dbi
CONFIGURE_ARGS+=	--enable-python-bindings

REPLACE_PERL+=		src/quotes/gnc-fq-dump
REPLACE_PERL+=		packaging/win32/exetype.pl
REPLACE_PERL+=		src/backend/xml/test/grab-types.pl
REPLACE_PERL+=		src/quotes/Quote_example.pl

PY_PATCHPLIST=		yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

PKG_SYSCONFSUBDIR=	gnucash
CONF_FILES+=		${PREFIX}/share/examples/gnucash/gnucash/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${PREFIX}/share/examples/gnucash/gnucash/environment ${PKG_SYSCONFDIR}/environment
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/gnucash

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

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../finance/libofx/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../misc/goffice0.8/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
