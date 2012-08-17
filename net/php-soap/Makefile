# $NetBSD: Makefile,v 1.5 2012/08/17 15:35:24 taca Exp $

MODNAME=		soap
CATEGORIES+=		net
COMMENT=		PHP extension for SOAP functions

MAINTAINER=		pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-soap-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
