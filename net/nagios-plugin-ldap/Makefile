# $NetBSD: Makefile,v 1.5 2006/10/23 07:17:40 seb Exp $
#

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}
CATEGORIES=	net sysutils databases

MAINTAINER=     pkgsrc-users@NetBSD.org
COMMENT=	Nagios ldap plugin

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}{,nb[0-9]*}:../../net/nagios-plugins

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_ldap

.include "../../net/nagios-plugins/Makefile.plugin"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
