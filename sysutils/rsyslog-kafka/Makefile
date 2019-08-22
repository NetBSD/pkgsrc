# $NetBSD: Makefile,v 1.10 2019/08/22 12:23:48 ryoon Exp $
#

RSYSLOG_MOD=	kafka
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	5

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-imkafka
CONFIGURE_ARGS+=	--enable-omkafka

BUILD_DIRS=		plugins/imkafka plugins/omkafka

.include "../../devel/librdkafka/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
