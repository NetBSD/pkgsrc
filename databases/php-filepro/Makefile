# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:13 jdolecek Exp $

MODNAME=		filepro
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for read-only filePro database access

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
