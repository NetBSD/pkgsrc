# $NetBSD: Makefile,v 1.6 2004/04/24 23:13:58 xtraeme Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for zlib compression

USE_BUILDLINK3=		YES
USE_BUILTIN.zlib=	yes

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}-dir=${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
