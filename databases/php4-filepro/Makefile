# $NetBSD: Makefile,v 1.3 2001/12/03 08:30:59 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		filepro
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for read-only filePro database access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
