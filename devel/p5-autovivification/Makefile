# $NetBSD: Makefile,v 1.16 2023/07/06 09:40:27 wiz Exp $

DISTNAME=	autovivification-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/V/VP/VPIT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/Tie-Cycle/lib/Tie/Cycle.pm
COMMENT=	Perl5 module to lexically disable autovivification
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/autovivification/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
