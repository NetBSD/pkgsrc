# $NetBSD: Makefile,v 1.2 2016/06/08 19:24:29 wiz Exp $

DISTNAME=	Lingua-EN-Syllable-0.251
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gregfast/Lingua-EN-Syllable-0.251/
COMMENT=	Routine for estimating syllable count in words
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Lingua/EN/Syllable/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
