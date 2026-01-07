# $NetBSD: Makefile,v 1.33 2026/01/07 08:48:59 wiz Exp $
#

RSYSLOG_MOD=	snmp
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	26

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-snmp

BUILD_DIRS=		plugins/mmsnmptrapd plugins/omsnmp

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
