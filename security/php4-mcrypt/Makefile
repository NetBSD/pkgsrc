# $NetBSD: Makefile,v 1.6 2002/06/09 19:01:12 jlam Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUILDLINK_ONLY=	yes

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../security/libmcrypt22/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
