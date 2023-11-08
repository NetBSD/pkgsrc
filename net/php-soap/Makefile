# $NetBSD: Makefile,v 1.14 2023/11/08 13:20:33 wiz Exp $

MODNAME=		soap
CATEGORIES+=		net
COMMENT=		PHP extension for SOAP functions
PKGREVISION=		8

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS=	php-soap-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
