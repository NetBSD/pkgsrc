# $NetBSD: Makefile,v 1.3 2001/12/03 08:31:01 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		posix
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for POSIX-like functions

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
