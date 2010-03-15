# $NetBSD: Makefile,v 1.7 2010/03/15 16:45:59 taca Exp $

MODNAME=		soap
CATEGORIES+=		net
COMMENT=		PHP5 extension for SOAP functions

MAINTAINER=		jdolecek@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-soap-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
