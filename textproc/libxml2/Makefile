# $NetBSD: Makefile,v 1.93.4.1 2008/09/11 12:22:36 ghen Exp $

DISTNAME=	libxml2-2.7.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://xmlsoft.org/libxml2/ \
		http://xmlsoft.org/sources/
#MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.7/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XML parser library from the GNOME project

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_FEATURES=		glob
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libxml-2.0.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-html-subdir=libxml2
CONFIGURE_ARGS+=	--without-python

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxml2
PKG_SUPPORTED_OPTIONS+=	inet6
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Don't use threads - it's not apparent whether it's necessary or not,
# and this library needs to be usable by non-threaded applications too
CONFIGURE_ARGS+=	--without-threads

# NetBSD-sparc64-1.6*'s f77 makes configure failing and as f77 is not
# needed for this package the following does no harm on other platforms.
CONFIGURE_ENV+=		F77=${FALSE:Q}

MAKE_ENV+=	PAX=${PAX:Q}

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_TOOLS+=	perl
TEST_TARGET=	check
.endif

SUBST_CLASSES+=		cat
SUBST_STAGE.cat=	pre-configure
SUBST_FILES.cat=	catalog.c xmlcatalog.c
SUBST_SED.cat=	-e "s,@@SGML_DEFAULT_CATALOG@@,${SGML_DEFAULT_CATALOG},g"
SUBST_SED.cat+=	-e "s,@@XML_DEFAULT_CATALOG@@,${XML_DEFAULT_CATALOG},g"

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"

.include "../../mk/bsd.pkg.mk"
