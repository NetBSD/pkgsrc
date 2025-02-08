# $NetBSD: Makefile,v 1.7 2025/02/08 03:15:20 taca Exp $

MODNAME=		ffi
PKGREVISION=		2
CATEGORIES+=		textproc
COMMENT=		PHP extension for Foreign Function Interface
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	74 81 82 83

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libffi}

.include "../../lang/php/ext.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
