# $NetBSD: Makefile,v 1.9 2004/02/22 00:42:27 minskim Exp $

DISTNAME=		Compress-Zlib-1.21
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5czl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		damon@brodiefamily.org
COMMENT=		Perl5 module interface to the zlib compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Compress/Zlib/.packlist
MAKE_ENV+=		ZLIB_LIB=${BUILDLINK_PREFIX.zlib}/lib
MAKE_ENV+=		ZLIB_INCLUDE=${BUILDLINK_PREFIX.zlib}/include

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
