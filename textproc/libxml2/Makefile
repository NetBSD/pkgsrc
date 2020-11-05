# $NetBSD: Makefile,v 1.157 2020/11/05 09:07:10 ryoon Exp $

.include "../../textproc/libxml2/Makefile.common"
PKGREVISION=	3

COMMENT=	XML parser library from the GNOME project
LICENSE=	modified-bsd

USE_FEATURES=		glob
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-subdir=libxml2
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-lzma=${BUILDLINK_PREFIX.xz}
CONFIGURE_ARGS+=	--without-python

PKGCONFIG_OVERRIDE=	libxml-2.0.pc.in

USE_LANGUAGES+=		c99

.include "options.mk"

# allow thread-awareness, but make sure the library is not
# linked against libpthread
#CONFIGURE_ARGS+=	--without-threads

MAKE_ENV+=	PAX=${PAX:Q}

TEST_TARGET=	check

SUBST_CLASSES+=		cat
SUBST_STAGE.cat=	pre-configure
SUBST_FILES.cat=	catalog.c xmlcatalog.c
SUBST_SED.cat=		-e "s,@@SGML_DEFAULT_CATALOG@@,${SGML_DEFAULT_CATALOG},g"
SUBST_SED.cat+=		-e "s,@@XML_DEFAULT_CATALOG@@,${XML_DEFAULT_CATALOG},g"

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wno-array-bounds
BUILDLINK_TRANSFORM.SunOS+=	rm:-Werror=format=2

LDFLAGS.SCO_SV+=	-lm

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
