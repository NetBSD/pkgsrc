# $NetBSD: Makefile,v 1.4 2002/02/28 06:18:43 jlam Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../security/libmcrypt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
