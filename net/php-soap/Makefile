# $NetBSD: Makefile,v 1.9 2021/04/21 11:42:28 adam Exp $

MODNAME=		soap
CATEGORIES+=		net
COMMENT=		PHP extension for SOAP functions
PKGREVISION=		3

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS=	php-soap-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
