# $NetBSD: Makefile,v 1.2 2010/08/17 06:48:37 sno Exp $
#

DISTNAME=	PPIx-Regexp-0.010
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WY/WYANT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPIx-Regexp/
COMMENT=	Represent a regular expression of some sort
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+=	p5-Params-Util>=0.25:../../devel/p5-Params-Util
DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPIx/Regexp/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
