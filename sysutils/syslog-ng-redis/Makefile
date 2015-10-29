# $NetBSD: Makefile,v 1.1 2015/10/29 16:34:14 fhajny Exp $

SYSLOG_MOD=		redis
COMMENT=		Syslog-ng Redis module

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-libhires=${BUILDLINK_PREFIX.hiredis}

.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
