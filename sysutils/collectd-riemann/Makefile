# $NetBSD: Makefile,v 1.9 2020/05/22 10:56:39 adam Exp $

COLLECTD_PACKAGE=	riemann
COLLECTD_PLUGINS=	write_riemann

COMMENT=		Statistics collection daemon - riemann plugin
PKGREVISION=		7

.include "../../sysutils/collectd/Makefile.common"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../sysutils/riemann-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
