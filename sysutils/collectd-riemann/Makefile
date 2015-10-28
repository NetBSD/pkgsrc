# $NetBSD: Makefile,v 1.1 2015/10/28 11:44:52 jperkin Exp $

COLLECTD_PACKAGE=	riemann
COLLECTD_PLUGINS=	write_riemann

COMMENT=		Statistics collection daemon - riemann plugin

.include "../../sysutils/collectd/Makefile.common"

# Work around incorrect dependencies in src/Makefile
BUILD_TARGET=		riemann.pb-c.lo write_riemann.la

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
