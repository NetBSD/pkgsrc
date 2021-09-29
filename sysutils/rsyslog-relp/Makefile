# $NetBSD: Makefile,v 1.18 2021/09/29 19:01:22 adam Exp $
#

RSYSLOG_MOD=	relp
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	12

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-relp

BUILD_DIRS=		plugins/imrelp plugins/omrelp

.include "../../devel/librelp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
