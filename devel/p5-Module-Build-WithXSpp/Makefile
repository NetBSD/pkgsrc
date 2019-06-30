# $NetBSD: Makefile,v 1.12 2019/06/30 20:15:18 nia Exp $

DISTNAME=	Module-Build-WithXSpp-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build-WithXSpp
COMMENT=	Build and install Perl XS++ modules
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.4,p5-Module-Build-[0-9]*}:../../devel/p5-Module-Build
DEPENDS+=	p5-ExtUtils-CppGuess-[0-9]*:../../devel/p5-ExtUtils-CppGuess
DEPENDS+=	p5-ExtUtils-XSpp-[0-9]*:../../devel/p5-ExtUtils-XSpp

#USE_LANGUAGES=	c	# For the tests

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Module/Build/WithXSpp/.packlist
# For the tests:
#USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
