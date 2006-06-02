# $NetBSD: Makefile,v 1.7 2006/06/02 18:27:54 joerg Exp $

MODNAME=		filepro
CATEGORIES+=		databases
COMMENT=		PHP extension for read-only filePro database access

CONFLICTS=	php-filepro-[0-9]

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
