# $NetBSD: Makefile,v 1.7 2011/10/17 11:50:05 obache Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.0
PKGREVISION=		2
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-perl=${PREFIX}

PHP_VERSIONS_ACCEPTED=	52

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
