# $NetBSD: Makefile,v 1.16 2021/04/21 13:25:24 adam Exp $

RSYSLOG_MOD=	omprog
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	11

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-omprog

BUILD_DIRS=		plugins/omprog

.include "../../mk/bsd.pkg.mk"
