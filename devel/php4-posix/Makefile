# $NetBSD: Makefile,v 1.6 2004/04/24 23:25:23 xtraeme Exp $

MODNAME=		posix
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for POSIX-like functions

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
