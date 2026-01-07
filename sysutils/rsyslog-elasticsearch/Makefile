# $NetBSD: Makefile,v 1.43 2026/01/07 08:48:57 wiz Exp $
#

RSYSLOG_MOD=	elasticsearch
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	26

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-elasticsearch

BUILD_DIRS=		plugins/omelasticsearch

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
