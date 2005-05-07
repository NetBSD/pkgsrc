# $NetBSD: Makefile,v 1.1.1.1 2005/05/07 19:28:01 jdolecek Exp $

MODNAME=		soap
CATEGORIES+=		net
COMMENT=		PHP5 extension for SOAP functions

MAINTAINER=		jdolecek@NetBSD.org


CONFIGURE_ARGS+=        --enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
