# $NetBSD: Makefile,v 1.6 2024/05/12 14:36:45 taca Exp $

MODNAME=		ffi
CATEGORIES+=		textproc
COMMENT=		PHP extension for Foreign Function Interface
PKGREVISION=		1
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	74 81 82 83

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libffi}

.include "../../lang/php/ext.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
