# $NetBSD: Makefile,v 1.5 2020/10/24 22:39:47 wiz Exp $

COLLECTD_PACKAGE=	mysql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${MYSQL_VERSION}/}
COMMENT=		Statistics collection daemon - mysql plugin

.include "../../mk/mysql.buildlink3.mk"
COLLECTD_LIB.mysql=	${BUILDLINK_PREFIX.mysql-client}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
