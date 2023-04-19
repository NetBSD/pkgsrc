# $NetBSD: Makefile,v 1.20 2023/04/19 08:11:32 adam Exp $
#

RSYSLOG_MOD=	dbi
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	15

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-libdbi

BUILD_DIRS=		plugins/omlibdbi

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
