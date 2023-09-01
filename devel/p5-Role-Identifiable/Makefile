# $NetBSD: Makefile,v 1.22 2023/09/01 02:53:39 wen Exp $

DISTNAME=	Role-Identifiable-0.009
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Role-Identifiable
COMMENT=	Perl 5 role with an ident attribute
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

TOOL_DEPENDS+=		p5-Moose-[0-9]*:../../devel/p5-Moose
#TOOL_DEPENDS+=	{perl>=5.14.1,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
# for make test
TOOL_DEPENDS+=		p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST=		auto/Role/Identifiable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
