# $NetBSD: Makefile,v 1.4 2020/08/31 18:11:25 wiz Exp $

COLLECTD_PACKAGE=	dbi

COMMENT=		Statistics collection daemon - dbi plugin
PKGREVISION=		3

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libdbi=${BUILDLINK_PREFIX.libdbi}

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
