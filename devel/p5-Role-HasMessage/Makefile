# $NetBSD: Makefile,v 1.23 2023/09/01 02:48:43 wen Exp $

DISTNAME=	Role-HasMessage-0.007
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Role-HasMessage
COMMENT=	Perl 5 role with a message method
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-String-Errf-[0-9]*:../../textproc/p5-String-Errf
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

TOOL_DEPENDS+=		p5-Moose-[0-9]*:../../devel/p5-Moose
#TOOL_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
# for make test
TOOL_DEPENDS+=		p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
TOOL_DEPENDS+=		p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST=		auto/Role/HasMessage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
