# $NetBSD: Makefile,v 1.22 2023/11/08 13:21:00 wiz Exp $
#

RSYSLOG_MOD=	dbi
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	17

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-libdbi

BUILD_DIRS=		plugins/omlibdbi

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
