# $NetBSD: Makefile,v 1.12 2018/08/22 09:44:28 wiz Exp $
#

DISTNAME=	PPIx-Utilities-1.001000
PKGNAME=	p5-${DISTNAME:S/001000/001.000/}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EL/ELLIOTJS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPIx-Utilities/
COMMENT=	Extensions to PPI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-PPI>=1.208:../../devel/p5-PPI
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

# recommended
DEPENDS+=	p5-PPI-XS-[0-9]*:../../devel/p5-PPI-XS
DEPENDS+=	p5-Readonly-XS-[0-9]*:../../devel/p5-Readonly-XS

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPIx/Utilities/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
