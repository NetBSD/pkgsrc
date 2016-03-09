# $NetBSD: Makefile,v 1.3 2016/03/09 20:55:35 fhajny Exp $
#

RSYSLOG_MOD=	elasticsearch
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-elasticsearch
BUILD_DIRS=	plugins/omelasticsearch

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
