# $NetBSD: Makefile,v 1.32 2025/04/19 07:58:27 wiz Exp $
#

RSYSLOG_MOD=	rabbitmq
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}
PKGREVISION=	24

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-omrabbitmq

BUILD_DIRS=		contrib/omrabbitmq

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
