# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:04 joerg Exp $

MODNAME=		zlib
PKGREVISION=		1
CATEGORIES+=		archivers
COMMENT=		PHP extension for zlib compression

CONFIGURE_ARGS+=	--with-${MODNAME}-dir=${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
