# $NetBSD: Makefile,v 1.6 2003/09/19 12:23:06 wiz Exp $

MODNAME=		bcmath
CATEGORIES+=		math
PKGREVISION=		# empty
COMMENT=		PHP4 extension for bc-style arbitrary precision math

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
