# $NetBSD: Makefile,v 1.8 2012/05/12 11:40:06 obache Exp $

MODNAME=		perl
PKGMODNAME=		perl
PECL_VERSION=		1.0.0
PKGREVISION=		2
CATEGORIES+=		lang
COMMENT=		PHP extension embedding Perl in PHP

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-perl=${PERLDIR}

.include "../../lang/php/phpversion.mk"
.if ${PKG_PHP_VERSION} == "5" || ${PKG_PHP_VERSION} == "52"
PECL_LEGACY_VERSION_SCHEME=	yes
.endif

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
