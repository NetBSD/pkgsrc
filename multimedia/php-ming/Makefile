# $NetBSD: Makefile,v 1.1.1.1 2005/11/04 04:53:16 minskim Exp $

MODNAME=		ming
CATEGORIES+=		multimedia

MAINTAINER=		obata@lins.jp
COMMENT=		PHP extension for Ming library

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}

.include "../../lang/php/ext.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
