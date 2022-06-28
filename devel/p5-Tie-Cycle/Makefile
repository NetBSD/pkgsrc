# $NetBSD: Makefile,v 1.16 2022/06/28 11:33:34 wiz Exp $

DISTNAME=	Tie-Cycle-1.226
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/Tie-Cycle/lib/Tie/Cycle.pm
COMMENT=	Perl5 module to cycle through a list of values
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Tie/Cycle/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
