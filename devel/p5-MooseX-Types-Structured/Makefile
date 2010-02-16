# $NetBSD: Makefile,v 1.5 2010/02/16 11:53:13 sno Exp $
#

DISTNAME=	MooseX-Types-Structured-0.20
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-Structured/
COMMENT=	Perl 5 module providing structured type constraints for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-PartialDump>=0.10:../../devel/p5-Devel-PartialDump
DEPENDS+=	p5-Moose>=0.63:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.08:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Sub-Exporter>=0.982:../../devel/p5-Sub-Exporter

# For test target
BUILD_DEPENDS+=	p5-MooseX-Types-DateTime-[0-9]*:../../time/p5-MooseX-Types-DateTime
BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/MooseX/Types/Structured/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
