# $NetBSD: Makefile,v 1.9 2018/08/22 09:44:56 wiz Exp $

DISTNAME=	autovivification-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
