# $NetBSD: Makefile,v 1.14 2020/05/06 14:05:03 adam Exp $

RSYSLOG_MOD=	omprog
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	9

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-omprog

BUILD_DIRS=		plugins/omprog

.include "../../mk/bsd.pkg.mk"
