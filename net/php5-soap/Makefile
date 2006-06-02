# $NetBSD: Makefile,v 1.3 2006/06/02 18:27:57 joerg Exp $

MODNAME=		soap
CATEGORIES+=		net
COMMENT=		PHP5 extension for SOAP functions

MAINTAINER=		jdolecek@NetBSD.org

CONFLICTS=	php-soap-[0-9]

PHP_VERSIONS_ACCEPTED=	5

CONFIGURE_ARGS+=        --enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
