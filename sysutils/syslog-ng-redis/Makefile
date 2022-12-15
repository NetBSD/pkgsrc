# $NetBSD: Makefile,v 1.4 2022/12/15 10:09:43 wiz Exp $

SYSLOG_MOD=		redis
COMMENT=		Syslog-ng Redis module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-libhires=${BUILDLINK_PREFIX.hiredis}

.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
