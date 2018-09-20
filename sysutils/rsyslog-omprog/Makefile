# $NetBSD: Makefile,v 1.5 2018/09/20 13:30:12 fhajny Exp $

RSYSLOG_MOD=	omprog
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-omprog

BUILD_DIRS=		plugins/omprog

.include "../../mk/bsd.pkg.mk"
