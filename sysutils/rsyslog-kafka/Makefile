# $NetBSD: Makefile,v 1.8 2019/07/01 04:08:48 ryoon Exp $
#

RSYSLOG_MOD=	kafka
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	3

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-imkafka
CONFIGURE_ARGS+=	--enable-omkafka

BUILD_DIRS=		plugins/imkafka plugins/omkafka

.include "../../devel/librdkafka/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
