# $NetBSD: Makefile,v 1.40 2026/05/14 16:42:04 ryoon Exp $

COLLECTD_PACKAGE=	riemann
COLLECTD_PLUGINS=	write_riemann

COMMENT=		Statistics collection daemon - riemann plugin
PKGREVISION=		29

.include "../../sysutils/riemann-client/buildlink3.mk"
COLLECTD_LIB.riemann-client=${BUILDLINK_PREFIX.riemann-client}

.include "../../devel/protobuf-c/buildlink3.mk"

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
