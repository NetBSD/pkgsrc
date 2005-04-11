# $NetBSD: Makefile,v 1.4 2005/04/11 21:44:50 tv Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP extension for zlib compression


CONFIGURE_ARGS+=	--with-${MODNAME}-dir=${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
