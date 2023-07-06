# $NetBSD: Makefile,v 1.77 2023/07/06 09:39:49 wiz Exp $

DISTNAME=	Params-Validate-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
