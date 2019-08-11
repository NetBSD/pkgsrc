# $NetBSD: Makefile,v 1.24 2019/08/11 13:20:00 wiz Exp $
#

DISTNAME=	MooseX-Singleton-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Singleton
COMMENT=	Perl 5 module to turn Moose class into a singleton
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Singleton/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Moose>=1.10:../../devel/p5-Moose

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
