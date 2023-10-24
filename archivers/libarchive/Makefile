# $NetBSD: Makefile,v 1.51 2023/10/24 22:08:08 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

COMMENT=	Library to read/create different archive formats

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-bsdcat
CONFIGURE_ARGS+=	--disable-bsdcpio
CONFIGURE_ARGS+=	--disable-bsdtar

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
