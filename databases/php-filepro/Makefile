# $NetBSD: Makefile,v 1.3 2004/11/05 17:11:39 jdolecek Exp $

MODNAME=		filepro
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for read-only filePro database access

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
