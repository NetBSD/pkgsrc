# $NetBSD: Makefile,v 1.3 2012/06/14 07:45:30 sbd Exp $

MODNAME=		soap
PKGREVISION=		1
CATEGORIES+=		net
COMMENT=		PHP5 extension for SOAP functions

MAINTAINER=		pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-soap-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
