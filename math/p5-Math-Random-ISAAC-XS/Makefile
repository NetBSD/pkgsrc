# $NetBSD: Makefile,v 1.14 2023/07/06 09:40:54 wiz Exp $
#

DISTNAME=	Math-Random-ISAAC-XS-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	math perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Random-ISAAC-XS
COMMENT=	C implementation of the ISAAC PRNG algorithm for Perl modules
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	p5-Test-NoWarnings>=0.084:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Math/Random/ISAAC/XS/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
