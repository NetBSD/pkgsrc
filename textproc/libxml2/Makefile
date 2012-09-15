# $NetBSD: Makefile,v 1.120 2012/09/15 10:23:38 adam Exp $

DISTNAME=	libxml2-2.9.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://xmlsoft.org/libxml2/ \
		http://xmlsoft.org/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XML parser library from the GNOME project
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES=		glob
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-subdir=libxml2
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--without-python

PKGCONFIG_OVERRIDE=	libxml-2.0.pc.in

.include "options.mk"

# allow thread-awareness, but make sure the library is not
# linked against libpthread
#CONFIGURE_ARGS+=	--without-threads

MAKE_ENV+=	PAX=${PAX:Q}

.include "../../mk/bsd.prefs.mk"

TEST_TARGET=	check

SUBST_CLASSES+=		cat
SUBST_STAGE.cat=	pre-configure
SUBST_FILES.cat=	catalog.c xmlcatalog.c
SUBST_SED.cat=	-e "s,@@SGML_DEFAULT_CATALOG@@,${SGML_DEFAULT_CATALOG},g"
SUBST_SED.cat+=	-e "s,@@XML_DEFAULT_CATALOG@@,${XML_DEFAULT_CATALOG},g"

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
