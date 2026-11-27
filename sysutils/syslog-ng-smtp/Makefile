# $NetBSD: Makefile,v 1.9 2026/11/27 11:01:44 adam Exp $

SYSLOG_MOD=		smtp
SYSLOG_MOD_DIR=		afsmtp
COMMENT=		Syslog-ng SMTP module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-libesmtp=${BUILDLINK_PREFIX.libesmtp}

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
