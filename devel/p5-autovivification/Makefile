# $NetBSD: Makefile,v 1.10 2019/07/01 21:35:45 nia Exp $

DISTNAME=	autovivification-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/V/VP/VPIT/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/Tie-Cycle/lib/Tie/Cycle.pm
COMMENT=	Perl5 module to lexically disable autovivification
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/autovivification/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
