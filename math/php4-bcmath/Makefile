# $NetBSD: Makefile,v 1.5 2003/08/31 19:55:49 jdolecek Exp $

MODNAME=		bcmath
CATEGORIES+=		math
PKGREVISION=		# empty
COMMENT=		PHP4 extension for bc-style arbitrary precision math

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${PKGDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
