# $NetBSD: Makefile,v 1.20 2023/04/19 08:11:33 adam Exp $

RSYSLOG_MOD=	omprog
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	15

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-omprog

BUILD_DIRS=		plugins/omprog

.include "../../mk/bsd.pkg.mk"
