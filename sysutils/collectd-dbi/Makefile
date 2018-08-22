# $NetBSD: Makefile,v 1.2 2018/08/22 09:46:32 wiz Exp $

COLLECTD_PACKAGE=	dbi

COMMENT=		Statistics collection daemon - dbi plugin
PKGREVISION=		1

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libdbi=${BUILDLINK_PREFIX.libdbi}

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
