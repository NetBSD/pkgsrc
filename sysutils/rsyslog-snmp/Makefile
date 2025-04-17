# $NetBSD: Makefile,v 1.30 2025/04/17 21:52:30 wiz Exp $
#

RSYSLOG_MOD=	snmp
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	23

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-snmp

BUILD_DIRS=		plugins/mmsnmptrapd plugins/omsnmp

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
