# $NetBSD: Makefile,v 1.1.1.1 2009/07/03 07:40:05 manu Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.0
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-perl=${PREFIX}

.include "../../lang/perl5/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
