# $NetBSD: Makefile,v 1.3 2019/12/16 16:30:13 taca Exp $

MODNAME=		recode
CATEGORIES=		converters
MAINTAINER=		evaldo@gardenali.biz
COMMENT=		PHP extension for recode support
LICENSE=		php

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.recode}

PHP_VERSIONS_ACCEPTED=	56 72 73
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../converters/recode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
