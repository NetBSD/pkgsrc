# $NetBSD: Makefile,v 1.33 2026/02/06 10:05:58 wiz Exp $
#

RSYSLOG_MOD=	relp
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	27

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-relp

BUILD_DIRS=		plugins/imrelp plugins/omrelp

.include "../../devel/librelp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
