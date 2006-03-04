# $NetBSD: Makefile,v 1.3 2006/03/04 21:30:04 jlam Exp $
#

DISTNAME=		Math-GMP-2.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mgp
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-GMP/
COMMENT=		Perl 5 module for high speed arbitrary size integer math

PERL5_PACKLIST=		auto/Math/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
