# $NetBSD: Makefile,v 1.5 2002/10/10 09:37:12 wiz Exp $

MODNAME=		zlib
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for zlib compression

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

post-extract:
	cd ${WRKSRC}; ${RM} -f config.m4; ${LN} -sf config0.m4 config.m4

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
