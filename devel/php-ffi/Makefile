# $NetBSD: Makefile,v 1.1 2021/03/08 00:07:09 taca Exp $

MODNAME=		ffi
CATEGORIES+=		textproc
COMMENT=		PHP extension for Foreign Function Interface
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	74 80

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libffi}

.include "../../lang/php/ext.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
