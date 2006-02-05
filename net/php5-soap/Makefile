# $NetBSD: Makefile,v 1.2 2006/02/05 23:10:29 joerg Exp $

MODNAME=		soap
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP5 extension for SOAP functions

MAINTAINER=		jdolecek@NetBSD.org


CONFIGURE_ARGS+=        --enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
