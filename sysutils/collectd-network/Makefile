# $NetBSD: Makefile,v 1.1.26.1 2017/04/23 10:02:37 bsiegert Exp $

COLLECTD_PACKAGE=	network
PKGREVISION=		1

COMMENT=		Statistics collection daemon - network plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libgcrypt=${BUILDLINK_PREFIX.libgcrypt}/bin/libgcrypt-config

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
