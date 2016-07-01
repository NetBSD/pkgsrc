# $NetBSD: Makefile,v 1.45 2016/07/01 17:55:22 jperkin Exp $

.include "Makefile.common"

PKGREVISION=	2
COMMENT=	Library to read/create different archive formats

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-bsdcat
CONFIGURE_ARGS+=	--disable-bsdcpio
CONFIGURE_ARGS+=	--disable-bsdtar

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

# workaround for pkg/45491
CONFIGURE_ENV.SunOS+=	ac_cv_header_ext2fs_ext2_fs_h=no

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
