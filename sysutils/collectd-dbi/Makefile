# $NetBSD: Makefile,v 1.1 2014/02/17 11:21:55 fhajny Exp $

COLLECTD_PACKAGE=	dbi

COMMENT=		Statistics collection daemon - dbi plugin

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libdbi=${BUILDLINK_PREFIX.libdbi}

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
