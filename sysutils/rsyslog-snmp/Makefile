# $NetBSD: Makefile,v 1.35 2026/05/14 16:42:11 ryoon Exp $
#

RSYSLOG_MOD=	snmp
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	28

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-snmp

BUILD_DIRS=		plugins/mmsnmptrapd plugins/omsnmp

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
