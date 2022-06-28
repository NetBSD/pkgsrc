# $NetBSD: Makefile,v 1.15 2022/06/28 11:33:35 wiz Exp $

DISTNAME=		Type-Tiny-XS-0.022
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
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
