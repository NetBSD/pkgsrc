# $NetBSD: Makefile,v 1.3 2002/02/28 06:18:24 jlam Exp $

MODNAME=		ftp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP4 extension for FTP access

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
