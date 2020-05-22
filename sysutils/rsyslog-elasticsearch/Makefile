# $NetBSD: Makefile,v 1.27 2020/05/22 10:56:41 adam Exp $
#

RSYSLOG_MOD=	elasticsearch
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	10

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-elasticsearch

BUILD_DIRS=		plugins/omelasticsearch

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
