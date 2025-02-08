# $NetBSD: Makefile,v 1.9 2025/02/08 03:15:21 taca Exp $

MODNAME=		pcntl
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for Process Control functions

CONFLICTS=	php-pcntl-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
