# $NetBSD: Makefile,v 1.1.1.1 2005/10/13 10:54:30 seb Exp $
#

DISTNAME=		Math-GMP-2.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mgp
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-GMP/
COMMENT=		Perl 5 module for high speed arbitrary size integer math

PERL5_PACKLIST=		auto/Math/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
