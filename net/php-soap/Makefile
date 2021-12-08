# $NetBSD: Makefile,v 1.10 2021/12/08 16:06:05 adam Exp $

MODNAME=		soap
CATEGORIES+=		net
COMMENT=		PHP extension for SOAP functions
PKGREVISION=		4

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS=	php-soap-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
