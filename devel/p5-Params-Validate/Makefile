# $NetBSD: Makefile,v 1.73 2021/04/26 14:56:03 wiz Exp $

DISTNAME=	Params-Validate-1.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Params-Validate
COMMENT=	Validate method/function parameters
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Implementation-[0-9]*:../../devel/p5-Module-Implementation

TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=		auto/Params/Validate/.packlist
MAKE_JOBS_SAFE=		no
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
