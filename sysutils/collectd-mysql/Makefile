# $NetBSD: Makefile,v 1.6 2021/06/23 20:33:17 nia Exp $

COLLECTD_PACKAGE=	mysql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${MYSQL_VERSION}/}
PKGREVISION=		1
COMMENT=		Statistics collection daemon - mysql plugin

.include "../../mk/mysql.buildlink3.mk"
COLLECTD_LIB.mysql=	${BUILDLINK_PREFIX.mysql-client}

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
