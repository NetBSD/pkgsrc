# $NetBSD: Makefile,v 1.22 2017/06/05 14:23:22 ryoon Exp $
#

DISTNAME=	MooseX-Types-Structured-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-Structured/
COMMENT=	Perl 5 module providing structured type constraints for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-PartialDump>=0.13:../../devel/p5-Devel-PartialDump
DEPENDS+=	p5-Moose>=1.08:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.22:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Sub-Exporter>=0.982:../../devel/p5-Sub-Exporter

# For test target
BUILD_DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
BUILD_DEPENDS+=	p5-MooseX-Types-DateTime-[0-9]*:../../time/p5-MooseX-Types-DateTime
BUILD_DEPENDS+=	p5-Class-Tiny-[0-9]*:../../devel/p5-Class-Tiny
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+= p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
#BUILD_DEPENDS+= {perl>=5.11.1,p5-Test-Simple>=0.94}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/MooseX/Types/Structured/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
