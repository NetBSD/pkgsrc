# $NetBSD: Makefile,v 1.9 2011/08/14 12:26:22 obache Exp $
#

DISTNAME=	MooseX-Role-Parameterized-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Role-Parameterized/
COMMENT=	Perl 5 module to create Moose roles with composition parameters
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Role/Parameterized/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Moose>=0.78:../../devel/p5-Moose

BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+= {perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
