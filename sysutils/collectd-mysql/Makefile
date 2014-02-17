# $NetBSD: Makefile,v 1.1 2014/02/17 11:21:55 fhajny Exp $

COLLECTD_PACKAGE=	mysql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${MYSQL_VERSION}/}
COMMENT=		Statistics collection daemon - mysql plugin

.include "../../sysutils/collectd/Makefile.common"


CONFIGURE_ARGS+=	--with-libmysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
