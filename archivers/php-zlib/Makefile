# $NetBSD: Makefile,v 1.25 2025/12/27 19:03:26 gutteridge Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
COMMENT=		PHP extension for zlib compression
PKGREVISION=		3

CONFLICTS=	php-zlib-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}-dir=${BUILDLINK_DIR}

.include "../../mk/compiler.mk"

# Needed for PHP 5.6 with GCC >= 14 on NetBSD.
.if ${PKGSRC_COMPILER:Mgcc}
CFLAGS+=	-Wno-error=incompatible-pointer-types
.endif

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
