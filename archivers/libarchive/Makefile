# $NetBSD: Makefile,v 1.41 2015/01/17 12:44:47 adam Exp $

.include "Makefile.common"

COMMENT=	Library to read/create different archive formats

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--disable-bsdcpio
CONFIGURE_ARGS+=	--disable-bsdtar

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
# workaround for pkg/45491
CONFIGURE_ENV+=		ac_cv_header_ext2fs_ext2_fs_h=no
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
