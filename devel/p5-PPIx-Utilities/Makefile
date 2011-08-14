# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:27 obache Exp $
#

DISTNAME=	PPIx-Utilities-1.000001
PKGNAME=	p5-${DISTNAME:S/000001/000.001/}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EL/ELLIOTJS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPIx-Utilities/
COMMENT=	Extensions to PPI
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-PPI>=1.208:../../devel/p5-PPI
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

# recommended
DEPENDS+=	p5-PPI-XS-[0-9]*:../../devel/p5-PPI-XS

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPIx/Utilities/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
