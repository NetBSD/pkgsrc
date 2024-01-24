# $NetBSD: Makefile,v 1.53 2024/01/24 23:01:26 adam Exp $

.include "Makefile.common"

COMMENT=	Library to read/create different archive formats

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-bsdcat
CONFIGURE_ARGS+=	--disable-bsdcpio
CONFIGURE_ARGS+=	--disable-bsdtar
CONFIGURE_ARGS+=	--disable-bsdunzip
CONFIGURE_ARGS+=	--without-iconv

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}
	# Contents of ${FILESDIR} may not have the u=w bit set, and
	# the build system assumes files in ${WRKSRC} are writable.
	${CHMOD} -R u+w ${WRKSRC}

# workaround for pkg/45491
CONFIGURE_ENV.SunOS+=	ac_cv_header_ext2fs_ext2_fs_h=no

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
