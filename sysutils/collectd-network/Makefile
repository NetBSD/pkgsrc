# $NetBSD: Makefile,v 1.3 2017/06/14 13:42:53 fhajny Exp $

COLLECTD_PACKAGE=	network

COMMENT=		Statistics collection daemon - network plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libgcrypt=${BUILDLINK_PREFIX.libgcrypt}/bin/libgcrypt-config

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
