# $NetBSD: Makefile,v 1.3 2019/08/11 13:23:04 wiz Exp $

COLLECTD_PACKAGE=	dbi

COMMENT=		Statistics collection daemon - dbi plugin
PKGREVISION=		2

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libdbi=${BUILDLINK_PREFIX.libdbi}

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
