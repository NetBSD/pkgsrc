# $NetBSD: Makefile,v 1.3 2001/12/03 08:31:04 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../security/libmcrypt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
