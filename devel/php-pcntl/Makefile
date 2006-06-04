# $NetBSD: Makefile,v 1.5 2006/06/04 16:26:53 joerg Exp $

MODNAME=		pcntl
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for Process Control functions

CONFLICTS=	php-pcntl-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
