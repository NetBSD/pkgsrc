# $NetBSD: Makefile,v 1.16 2021/12/08 16:06:27 adam Exp $

COLLECTD_PACKAGE=	riemann
COLLECTD_PLUGINS=	write_riemann

COMMENT=		Statistics collection daemon - riemann plugin
PKGREVISION=		5

.include "../../sysutils/riemann-client/buildlink3.mk"
COLLECTD_LIB.riemann-client=${BUILDLINK_PREFIX.riemann-client}

.include "../../devel/protobuf-c/buildlink3.mk"

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
