# $NetBSD: Makefile,v 1.4 2002/02/28 06:17:39 jlam Exp $

MODNAME=		posix
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for POSIX-like functions

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
