# $NetBSD: Makefile,v 1.5.2.1 2002/06/23 18:59:18 jlam Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUILDLINK_ONLY=	yes

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../security/libmcrypt22/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
