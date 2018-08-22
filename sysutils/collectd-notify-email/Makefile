# $NetBSD: Makefile,v 1.4 2018/08/22 09:46:32 wiz Exp $

COLLECTD_PACKAGE=	notify-email

COMMENT=		Statistics collection daemon - notify_email plugin
PKGREVISION=		1

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libesmtp=${BUILDLINK_PREFIX.libesmtp}

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
