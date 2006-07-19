# $NetBSD: Makefile,v 1.19 2006/07/19 22:36:26 wiz Exp $

DISTNAME=		Compress-Zlib-1.42
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5czl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://search.cpan.org/dist/Compress-Zlib/
COMMENT=		Perl5 module interface to the zlib compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Compress/Zlib/.packlist
MAKE_ENV+=		BUILD_ZLIB=False
MAKE_ENV+=		OLD_ZLIB=False
MAKE_ENV+=		ZLIB_LIB=${BUILDLINK_PREFIX.zlib}/lib
MAKE_ENV+=		ZLIB_INCLUDE=${BUILDLINK_PREFIX.zlib}/include

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
