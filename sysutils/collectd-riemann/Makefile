# $NetBSD: Makefile,v 1.32 2024/12/26 23:57:22 adam Exp $

COLLECTD_PACKAGE=	riemann
COLLECTD_PLUGINS=	write_riemann

COMMENT=		Statistics collection daemon - riemann plugin
PKGREVISION=		21

.include "../../sysutils/riemann-client/buildlink3.mk"
COLLECTD_LIB.riemann-client=${BUILDLINK_PREFIX.riemann-client}

.include "../../devel/protobuf-c/buildlink3.mk"

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
