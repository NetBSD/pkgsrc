# $NetBSD: Makefile,v 1.6 2002/09/24 23:05:05 seb Exp $

DISTNAME=		Compress-Zlib-1.16
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5czl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		damon@brodiefamily.org
COMMENT=		perl5 module interface to the zlib compression library

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Compress/Zlib/.packlist
MAKE_ENV+=		ZLIB_LIB=${BUILDLINK_PREFIX.zlib}/lib
MAKE_ENV+=		ZLIB_INCLUDE=${BUILDLINK_PREFIX.zlib}/include

.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
