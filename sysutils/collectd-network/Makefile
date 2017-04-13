# $NetBSD: Makefile,v 1.2 2017/04/13 17:48:27 fhajny Exp $

COLLECTD_PACKAGE=	network
PKGREVISION=		1

COMMENT=		Statistics collection daemon - network plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libgcrypt=${BUILDLINK_PREFIX.libgcrypt}/bin/libgcrypt-config

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
