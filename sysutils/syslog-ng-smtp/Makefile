# $NetBSD: Makefile,v 1.4 2020/01/18 21:50:59 jperkin Exp $

SYSLOG_MOD=		smtp
SYSLOG_MOD_DIR=		afsmtp
COMMENT=		Syslog-ng SMTP module
PKGREVISION=		1

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-libesmtp=${BUILDLINK_PREFIX.libesmtp}

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
