# $NetBSD: Makefile,v 1.4 2002/02/28 06:16:44 jlam Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for zlib compression

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
