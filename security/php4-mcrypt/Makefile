# $NetBSD: Makefile,v 1.5 2002/04/12 19:03:34 jlam Exp $

MODNAME=		mcrypt
CATEGORIES+=		security
PKGREVISION=		# empty
COMMENT=		PHP4 extension for the mcrypt crypto algorithms library

USE_BUIDLINK_ONLY=	yes

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../security/libmcrypt22/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
