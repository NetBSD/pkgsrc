# $NetBSD: Makefile,v 1.1.1.1 2006/02/18 17:23:43 bouyer Exp $
#

PKGNAME=	nagios-plugin-snmp-${PLUGINSVERSION}
CATEGORIES=     net sysutils

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	Nagios snmp plugins

DEPENDS+=	nagios-plugins-${PLUGINSVERSION}:../../net/nagios-plugins
DEPENDS+=       p5-Net-SNMP-[0-9]*:../../net/p5-Net-SNMP

.include "../../net/nagios-plugins/Makefile.common"

BINARY_TARGET=	check_snmp check_hpjd
SCRIPT_TARGET=	check_ifoperstatus check_ifstatus
SCRIPT_TARGET+=	check_breeze check_wave

.include "../../net/nagios-plugins/Makefile.plugin"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
