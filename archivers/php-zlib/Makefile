# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:13 jdolecek Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP extension for zlib compression

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}-dir=${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
