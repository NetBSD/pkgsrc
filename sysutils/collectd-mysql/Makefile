# $NetBSD: Makefile,v 1.2 2018/08/22 09:46:32 wiz Exp $

COLLECTD_PACKAGE=	mysql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${MYSQL_VERSION}/}
PKGREVISION=		1
COMMENT=		Statistics collection daemon - mysql plugin

.include "../../sysutils/collectd/Makefile.common"


CONFIGURE_ARGS+=	--with-libmysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
