# $NetBSD: Makefile,v 1.3 2001/12/31 23:55:19 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		zlib
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for zlib compression

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
