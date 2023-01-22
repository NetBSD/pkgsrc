# $NetBSD: Makefile,v 1.166 2023/01/22 10:30:08 wiz Exp $

.include "../../textproc/libxml2/Makefile.common"

COMMENT=	XML parser library from the GNOME project
LICENSE=	modified-bsd

USE_FEATURES=		glob
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/libxml2
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-lzma=${BUILDLINK_PREFIX.xz}
CONFIGURE_ARGS+=	--without-python

PKGCONFIG_OVERRIDE=	libxml-2.0.pc.in

USE_LANGUAGES+=		c99

TEST_TARGET=	check

.include "options.mk"

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
