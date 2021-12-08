# $NetBSD: Makefile,v 1.3 2021/12/08 16:06:38 adam Exp $

SYSLOG_MOD=		redis
COMMENT=		Syslog-ng Redis module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-libhires=${BUILDLINK_PREFIX.hiredis}

.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
