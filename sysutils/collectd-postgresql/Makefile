# $NetBSD: Makefile,v 1.4 2016/10/09 21:42:03 wiz Exp $

COLLECTD_PACKAGE=	postgresql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${PGSQL_VERSION}/}
PKGREVISION=		1
COMMENT=		Statistics collection daemon - postgresql plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libpq=${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
