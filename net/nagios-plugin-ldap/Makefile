# $NetBSD: Makefile,v 1.16 2015/04/03 18:18:00 rodent Exp $
#

PKGNAME=	nagios-plugin-ldap-${PLUGINSVERSION}
CATEGORIES=	net sysutils databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Nagios ldap plugin
LICENSE=	gnu-gpl-v3

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}{,nb[0-9]*}:../../net/nagios-plugins

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_ldap

.include "../../net/nagios-plugins/Makefile.plugin"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
