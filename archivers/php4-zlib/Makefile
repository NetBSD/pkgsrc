# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 07:03:01 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		zlib
PHP_PKG_VERS=		# empty
CATEGORIES+=		archivers
COMMENT=		PHP4 extension for zlib compression

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf zlib.m4 config.m4

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
