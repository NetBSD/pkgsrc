# $NetBSD: Makefile,v 1.4 2022/12/11 14:17:26 taca Exp $

MODNAME=		ffi
CATEGORIES+=		textproc
COMMENT=		PHP extension for Foreign Function Interface
PKGREVISION=		1
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	74 80 81 82

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libffi}

.include "../../lang/php/ext.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
