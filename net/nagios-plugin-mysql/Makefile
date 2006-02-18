# $NetBSD: Makefile,v 1.1.1.1 2006/02/18 17:21:58 bouyer Exp $
#

PKGNAME=	nagios-plugin-mysql-${PLUGINSVERSION}
CATEGORIES=   	net sysutils databases

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	Nagios mysql plugin

DEPENDS+=       nagios-plugins-${PLUGINSVERSION}:../../net/nagios-plugins

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_mysql

.include "../../net/nagios-plugins/Makefile.plugin"
.include "../../mk/mysql.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
