# $NetBSD: Makefile,v 1.5 2008/01/18 05:08:44 tnn Exp $
#

PKGNAME=	nagios-plugin-mysql-${PLUGINSVERSION}
PKGREVISION=	1
CATEGORIES=	net sysutils databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Nagios mysql plugin

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}{,nb[0-9]*}:../../net/nagios-plugins

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_mysql

.include "../../net/nagios-plugins/Makefile.plugin"
.include "../../mk/mysql.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
