# $NetBSD: Makefile,v 1.180 2024/05/29 16:34:37 adam Exp $

PKGREVISION= 1
.include "../../textproc/libxml2/Makefile.common"

COMMENT=	XML parser library from the GNOME project
LICENSE=	modified-bsd

USE_FEATURES=		glob
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-lzma=${BUILDLINK_PREFIX.xz}
CONFIGURE_ARGS+=	--with-ftp
CONFIGURE_ARGS+=	--with-legacy
CONFIGURE_ARGS+=	--without-python

PKGCONFIG_OVERRIDE=	libxml-2.0.pc.in

USE_LANGUAGES+=		c
FORCE_C_STD=		c99

# for struct addrinfo on glibc
CPPFLAGS.Linux+=	-D_POSIX_C_SOURCE=200112L  

TEST_TARGET=	check

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath=	configure
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

.include "options.mk"

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
