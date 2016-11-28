# $NetBSD: Makefile,v 1.3 2016/11/28 12:29:48 wen Exp $

DISTNAME=		Math-BigInt-1.999801
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-BigInt/
COMMENT=		Arbitrary size integer math perl package
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/BigInt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
