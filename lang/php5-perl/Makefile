# $NetBSD: Makefile,v 1.6 2011/10/16 12:17:44 taca Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.0
PKGREVISION=		2
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-perl=${PREFIX}

PHP_VERSION_REQD=	52

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
