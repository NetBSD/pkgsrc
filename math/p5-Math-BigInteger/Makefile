# $NetBSD: Makefile,v 1.25 2016/06/08 19:24:02 wiz Exp $

DISTNAME=	Math-BigInteger-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Arbitrary length integer extension module for Perl
HOMEPAGE=	http://search.cpan.org/dist/Math-BigInteger/

PERL5_PACKLIST=		auto/Math/BigInteger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
