# $NetBSD: Makefile,v 1.2 2001/12/03 08:31:02 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		bcmath
CATEGORIES+=		math
PKGREVISION=		# empty
COMMENT=		PHP4 extension for bc-style arbitrary precision math

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
