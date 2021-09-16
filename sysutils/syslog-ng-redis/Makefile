# $NetBSD: Makefile,v 1.2 2021/09/16 09:22:47 wiz Exp $

SYSLOG_MOD=		redis
COMMENT=		Syslog-ng Redis module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-libhires=${BUILDLINK_PREFIX.hiredis}

.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
