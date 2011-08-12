# $NetBSD: Makefile,v 1.35 2011/08/12 06:52:03 adam Exp $

DISTNAME=	Date-Manip-6.24
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dma
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Date-Manip/
COMMENT=	Perl5 module for date calculations
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck
# only needed for tests
#DEPENDS+=	p5-Test-Inter-[0-9]*:../../devel/p5-Test-Inter

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Date/Manip/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
