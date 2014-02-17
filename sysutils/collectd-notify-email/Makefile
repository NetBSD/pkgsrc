# $NetBSD: Makefile,v 1.1 2014/02/17 11:21:55 fhajny Exp $

COLLECTD_PACKAGE=	notify-email

COMMENT=		Statistics collection daemon - notify_email plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libesmtp=${BUILDLINK_PREFIX.libesmtp}

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
