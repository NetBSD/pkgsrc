# $NetBSD: Makefile,v 1.3 2019/08/11 13:23:05 wiz Exp $

COLLECTD_PACKAGE=	mysql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${MYSQL_VERSION}/}
PKGREVISION=		2
COMMENT=		Statistics collection daemon - mysql plugin

.include "../../sysutils/collectd/Makefile.common"


CONFIGURE_ARGS+=	--with-libmysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
