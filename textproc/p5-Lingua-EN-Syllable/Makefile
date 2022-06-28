# $NetBSD: Makefile,v 1.12 2022/06/28 11:36:18 wiz Exp $

DISTNAME=	Lingua-EN-Syllable-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
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
