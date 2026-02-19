# $NetBSD: Makefile,v 1.195 2026/02/19 15:09:47 wiz Exp $

.include "../../textproc/libxml2/Makefile.common"

COMMENT=	XML parser library from the GNOME project
LICENSE=	modified-bsd

USE_FEATURES=		glob
USE_LANGUAGES=		c
FORCE_C_STD=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_ICONV=	no
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
# enable http ABI compatibility (feature is gone)
# to fix libspatialite:
# https://www.gaia-gis.it/fossil/libspatialite/tktview?name=2b1697e601
CONFIGURE_ARGS+=	--with-http
CONFIGURE_ARGS+=	--with-legacy
CONFIGURE_ARGS+=	--without-python
TEST_TARGET=		check

# /usr/include might not exist on some platforms, like Darwin.
# If so, cmake fails with non-existent path.
.include "../../converters/libiconv/buildlink3.mk"
CHECK_BUILTIN.iconv:=   yes
.include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.iconv:=   no

.if ${USE_BUILTIN.iconv:U:tl} == no
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=	--with-iconv
.endif

PKGCONFIG_OVERRIDE=	libxml-2.0.pc.in

# for struct addrinfo on glibc
CPPFLAGS.Linux+=	-D_POSIX_C_SOURCE=200112L

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath=	configure
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100500
BUILDLINK_TRANSFORM+=	rm:-Wno-array-bounds
.endif

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
