# $NetBSD: Makefile,v 1.19 2025/02/08 03:18:21 taca Exp $

MODNAME=		soap
PKGREVISION=		13
CATEGORIES+=		net
COMMENT=		PHP extension for SOAP functions

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS=	php-soap-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
