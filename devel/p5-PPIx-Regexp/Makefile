# $NetBSD: Makefile,v 1.51 2023/08/25 06:46:22 wen Exp $

DISTNAME=	PPIx-Regexp-0.088
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WY/WYANT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PPIx-Regexp
COMMENT=	Represent a regular expression of some sort
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PPI>=1.238:../../devel/p5-PPI
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPIx/Regexp/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
