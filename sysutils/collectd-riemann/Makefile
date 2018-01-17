# $NetBSD: Makefile,v 1.3 2018/01/17 12:10:38 jperkin Exp $

COLLECTD_PACKAGE=	riemann
COLLECTD_PLUGINS=	write_riemann

COMMENT=		Statistics collection daemon - riemann plugin
PKGREVISION=		1

.include "../../sysutils/collectd/Makefile.common"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../sysutils/riemann-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
