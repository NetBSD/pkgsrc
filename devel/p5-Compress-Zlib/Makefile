# $NetBSD: Makefile,v 1.14.2.1 2005/08/02 04:21:01 snj Exp $

DISTNAME=		Compress-Zlib-1.35
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5czl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://search.cpan.org/dist/Compress-Zlib/
COMMENT=		Perl5 module interface to the zlib compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Compress/Zlib/.packlist
MAKE_ENV+=		BUILD_ZLIB=False
MAKE_ENV+=		OLD_ZLIB=False
MAKE_ENV+=		ZLIB_LIB=${BUILDLINK_PREFIX.zlib}/lib
MAKE_ENV+=		ZLIB_INCLUDE=${BUILDLINK_PREFIX.zlib}/include

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
