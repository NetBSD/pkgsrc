# $NetBSD: Makefile,v 1.33 2022/06/28 11:32:53 wiz Exp $

DISTNAME=	MooseX-MethodAttributes-0.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-MethodAttributes
COMMENT=	Perl5 module for code attribute introspection
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.98:../../devel/p5-Moose
DEPENDS+=	p5-namespace-clean>=0.10:../../devel/p5-namespace-clean

TEST_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=		p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=		p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=		p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
TEST_DEPENDS+=		p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized

PERL5_PACKLIST=	auto/MooseX/MethodAttributes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
