# $NetBSD: Makefile,v 1.4 2006/06/04 16:26:54 joerg Exp $

MODNAME=		ming
CATEGORIES+=		multimedia

MAINTAINER=		obata@lins.jp
COMMENT=		PHP extension for Ming library

CONFLICTS=	php-ming-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.ming}

.include "../../lang/php/ext.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
