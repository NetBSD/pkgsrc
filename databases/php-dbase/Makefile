# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:13 jdolecek Exp $

MODNAME=		dbase
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for dBase database access

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
