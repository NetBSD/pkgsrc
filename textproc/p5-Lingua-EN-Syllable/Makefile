# $NetBSD: Makefile,v 1.17 2026/07/16 19:05:02 wiz Exp $

DISTNAME=	Lingua-EN-Syllable-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neilb/Lingua-EN-Syllable
COMMENT=	Routine for estimating syllable count in words
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Lingua/EN/Syllable/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
