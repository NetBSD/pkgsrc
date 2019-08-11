# $NetBSD: Makefile,v 1.7 2019/08/11 13:23:05 wiz Exp $

COLLECTD_PACKAGE=	postgresql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${PGSQL_VERSION}/}
PKGREVISION=		2
COMMENT=		Statistics collection daemon - postgresql plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libpq=${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
