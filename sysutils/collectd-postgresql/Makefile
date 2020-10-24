# $NetBSD: Makefile,v 1.9 2020/10/24 22:39:47 wiz Exp $

COLLECTD_PACKAGE=	postgresql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${PGSQL_VERSION}/}
COMMENT=		Statistics collection daemon - postgresql plugin

.include "../../mk/pgsql.buildlink3.mk"
COLLECTD_LIB.pq=	${PGSQL_PREFIX}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
