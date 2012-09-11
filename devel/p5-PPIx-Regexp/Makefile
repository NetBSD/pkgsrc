# $NetBSD: Makefile,v 1.8 2012/09/11 08:54:08 sno Exp $
#

DISTNAME=	PPIx-Regexp-0.028
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WY/WYANT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPIx-Regexp/
COMMENT=	Represent a regular expression of some sort
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-PPI>=1.117:../../devel/p5-PPI
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPIx/Regexp/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
