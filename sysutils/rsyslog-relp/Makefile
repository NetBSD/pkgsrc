# $NetBSD: Makefile,v 1.15 2020/05/06 14:05:03 adam Exp $
#

RSYSLOG_MOD=	relp
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	9

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-relp

BUILD_DIRS=		plugins/imrelp plugins/omrelp

.include "../../devel/librelp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
