# $NetBSD: Makefile,v 1.7 2017/08/14 19:21:33 wiz Exp $

DISTNAME=	autovivification-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/V/VP/VPIT/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Cycle/lib/Tie/Cycle.pm
COMMENT=	Perl5 module to lexically disable autovivification
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/autovivification/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
