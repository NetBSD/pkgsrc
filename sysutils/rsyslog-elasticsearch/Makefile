# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:31 jperkin Exp $
#

RSYSLOG_MOD=	elasticsearch
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	1

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-elasticsearch
BUILD_DIRS=	plugins/omelasticsearch

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
