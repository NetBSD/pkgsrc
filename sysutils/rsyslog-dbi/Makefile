# $NetBSD: Makefile,v 1.32 2026/02/06 10:05:57 wiz Exp $
#

RSYSLOG_MOD=	dbi
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	27

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-libdbi

BUILD_DIRS=		plugins/omlibdbi

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
