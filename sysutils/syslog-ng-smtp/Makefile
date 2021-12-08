# $NetBSD: Makefile,v 1.6 2021/12/08 16:06:38 adam Exp $

SYSLOG_MOD=		smtp
SYSLOG_MOD_DIR=		afsmtp
COMMENT=		Syslog-ng SMTP module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-libesmtp=${BUILDLINK_PREFIX.libesmtp}

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
