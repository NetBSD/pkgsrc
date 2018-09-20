# $NetBSD: Makefile,v 1.8 2018/09/20 13:30:12 fhajny Exp $
#

RSYSLOG_MOD=	rabbitmq
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../sysutils/rsyslog

.include "../../sysutils/rsyslog/Makefile.common"

CONFIGURE_ARGS+=	--enable-omrabbitmq

BUILD_DIRS=		contrib/omrabbitmq

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
