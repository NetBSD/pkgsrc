# $NetBSD: Makefile,v 1.45 2021/05/24 19:51:19 wiz Exp $

DISTNAME=	PPIx-Regexp-0.080
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WY/WYANT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PPIx-Regexp
COMMENT=	Represent a regular expression of some sort
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PPI>=1.117:../../devel/p5-PPI
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPIx/Regexp/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
