# $NetBSD: Makefile,v 1.13 2013/05/31 12:41:12 wiz Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.0
PKGREVISION=		4
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PHP_VERSIONS_ACCEPTED=	53

CONFIGURE_ARGS+=	--with-perl=${PERLDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
