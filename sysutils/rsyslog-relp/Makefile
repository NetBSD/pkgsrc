# $NetBSD: Makefile,v 1.12 2020/01/12 20:20:45 ryoon Exp $
#

RSYSLOG_MOD=	relp
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	6

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-relp

BUILD_DIRS=		plugins/imrelp plugins/omrelp

.include "../../devel/librelp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
