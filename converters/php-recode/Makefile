# $NetBSD: Makefile,v 1.5 2021/12/29 06:05:18 taca Exp $

MODNAME=		recode
CATEGORIES=		converters
MAINTAINER=		evaldo@gardenali.biz
COMMENT=		PHP extension for recode support
LICENSE=		php

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.recode}

PHP_VERSIONS_ACCEPTED=	56
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
