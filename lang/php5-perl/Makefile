# $NetBSD: Makefile,v 1.3 2010/03/16 11:56:22 taca Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.0
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-perl=${PREFIX}

PHP_VERSION_REQD=	5

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
