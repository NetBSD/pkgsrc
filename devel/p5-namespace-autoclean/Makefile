# $NetBSD: Makefile,v 1.29 2022/06/28 11:33:40 wiz Exp $

DISTNAME=	namespace-autoclean-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=namespace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/namespace-autoclean
COMMENT=	Keep imports out of your namespace
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-B-Hooks-EndOfScope-[0-9]*:../../devel/p5-B-Hooks-EndOfScope
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean
DEPENDS+=	p5-Sub-Identify-[0-9]*:../../devel/p5-Sub-Identify

# for make test
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
TEST_DEPENDS+=	p5-Mouse-[0-9]*:../../devel/p5-Mouse
TEST_DEPENDS+=	p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized

# used by some tests but would introduce cyclic dependency
TEST_DEPENDS+=	p5-Moose>=2:../../devel/p5-Moose

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/namespace/autoclean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
