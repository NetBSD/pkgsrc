# $NetBSD: Makefile,v 1.15 2015/02/26 15:55:20 taca Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.1
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PHP_VERSIONS_ACCEPTED=	53

CONFIGURE_ARGS+=	--with-perl=${PERLDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
