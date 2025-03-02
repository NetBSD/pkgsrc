# $NetBSD: Makefile,v 1.8 2025/03/02 19:52:26 wiz Exp $

MODNAME=		ffi
PKGREVISION=		2
CATEGORIES+=		textproc
COMMENT=		PHP extension for Foreign Function Interface
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	74 81 82 83 84

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libffi}

.include "../../lang/php/ext.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
