# $NetBSD: Makefile,v 1.12 2020/09/07 10:23:05 wiz Exp $

DISTNAME=		Type-Tiny-XS-0.021
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Type-Tiny-XS
COMMENT=		XS boost for some of Type::Tiny's type constraints
LICENSE=		${PERL5_LICENSE}

TEST_DEPENDS+=		p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny

PERL5_PACKLIST=		auto/Type/Tiny/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
