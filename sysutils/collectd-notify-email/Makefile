# $NetBSD: Makefile,v 1.3 2016/10/13 15:17:28 fhajny Exp $

COLLECTD_PACKAGE=	notify-email

COMMENT=		Statistics collection daemon - notify_email plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libesmtp=${BUILDLINK_PREFIX.libesmtp}

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
