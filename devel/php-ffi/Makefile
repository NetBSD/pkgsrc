# $NetBSD: Makefile,v 1.9 2026/01/08 13:39:19 taca Exp $

MODNAME=		ffi
PKGREVISION=		2
CATEGORIES+=		textproc
COMMENT=		PHP extension for Foreign Function Interface
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	74 81 82 83 84 85

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libffi}

.include "../../lang/php/ext.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
