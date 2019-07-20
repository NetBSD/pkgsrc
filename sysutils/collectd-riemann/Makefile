# $NetBSD: Makefile,v 1.6 2019/07/20 22:46:50 wiz Exp $

COLLECTD_PACKAGE=	riemann
COLLECTD_PLUGINS=	write_riemann

COMMENT=		Statistics collection daemon - riemann plugin
PKGREVISION=		4

.include "../../sysutils/collectd/Makefile.common"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../sysutils/riemann-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
