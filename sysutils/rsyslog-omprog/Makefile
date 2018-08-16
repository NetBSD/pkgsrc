# $NetBSD: Makefile,v 1.4 2018/08/16 18:55:12 adam Exp $

RSYSLOG_MOD=	omprog
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	1

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-omprog

BUILD_DIRS=		plugins/omprog

.include "../../mk/bsd.pkg.mk"
