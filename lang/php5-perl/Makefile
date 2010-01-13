# $NetBSD: Makefile,v 1.2 2010/01/13 22:47:40 joerg Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.0
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-perl=${PREFIX}

PHP_VERSIONS_ACCEPTED=		5

.include "../../lang/perl5/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
