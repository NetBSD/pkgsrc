# $NetBSD: Makefile,v 1.2 2009/09/12 20:43:19 sno Exp $
#

DISTNAME=	MooseX-Role-Parameterized-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Role-Parameterized/
COMMENT=	Perl 5 module to create Moose roles with composition parameters
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Role/Parameterized/.packlist
# the 'Module::Install' specific target in lang/perl5/module.mk
# removes a Module::Install extension bundled in the distfile so
# we use the PERL5_MODULE_TYPE's default
#PERL5_MODULE_TYPE=	Module::Install

DEPENDS+=	p5-Moose>=0.78:../../devel/p5-Moose
BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
