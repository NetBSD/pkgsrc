# $NetBSD: Makefile,v 1.4 2002/02/28 06:16:59 jlam Exp $

MODNAME=		filepro
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for read-only filePro database access

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
