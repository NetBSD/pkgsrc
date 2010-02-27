# $NetBSD: Makefile,v 1.14 2010/02/27 03:35:11 taca Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
COMMENT=		PHP extension for zlib compression

CONFLICTS=	php-zlib-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${MODNAME}-dir=${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
