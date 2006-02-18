# $NetBSD: Makefile,v 1.1.1.1 2006/02/18 17:22:57 bouyer Exp $
#

PKGNAME=	nagios-plugin-pgsql-${PLUGINSVERSION}
CATEGORIES=   	net sysutils databases

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	Nagios pgsql plugin

DEPENDS+=       nagios-plugins-${PLUGINSVERSION}:../../net/nagios-plugins

CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.pgsql-lib}
#CPPFLAGS+=		-I${PGSQL_PREFIX}/include/pgsql

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_pgsql

.include "../../net/nagios-plugins/Makefile.plugin"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
