# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 19:30:30 jdolecek Exp $

MODNAME=		posix
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP extension for POSIX-like functions

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
