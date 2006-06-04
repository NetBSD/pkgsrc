# $NetBSD: Makefile,v 1.9 2006/06/04 16:26:52 joerg Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
COMMENT=		PHP extension for zlib compression

CONFLICTS=	php-zlib-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}-dir=${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
