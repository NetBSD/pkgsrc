# $NetBSD: Makefile,v 1.4 2020/10/24 22:39:47 wiz Exp $

COLLECTD_PACKAGE=	network

COMMENT=		Statistics collection daemon - network plugin

.include "../../security/libgcrypt/buildlink3.mk"
COLLECTD_LIB.gcrypt=	${BUILDLINK_PREFIX.libgcrypt}/bin/libgcrypt-config

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
