# $NetBSD: Makefile,v 1.10 2012/06/18 15:14:19 taca Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.0
PKGREVISION=		2
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PKG_DESTDIR_SUPPORT=	user-destdir

PHP_VERSIONS_ACCEPTED=	53

CONFIGURE_ARGS+=	--with-perl=${PERLDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
