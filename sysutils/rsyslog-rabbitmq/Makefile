# $NetBSD: Makefile,v 1.1 2014/09/05 07:15:41 fhajny Exp $
#

RSYSLOG_MOD=	rabbitmq
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-omrabbitmq

BUILD_DIRS=		plugins/omrabbitmq

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
