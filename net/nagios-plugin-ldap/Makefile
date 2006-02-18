# $NetBSD: Makefile,v 1.1.1.1 2006/02/18 17:20:43 bouyer Exp $
#

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}
CATEGORIES=	net sysutils databases

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	Nagios ldap plugin

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}:../../net/nagios-plugins

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_ldap

.include "../../net/nagios-plugins/Makefile.plugin"
.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
