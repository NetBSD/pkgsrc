# $NetBSD: Makefile,v 1.20 2025/04/17 21:52:01 wiz Exp $

MODNAME=		soap
PKGREVISION=		14
CATEGORIES+=		net
COMMENT=		PHP extension for SOAP functions

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS=	php-soap-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
