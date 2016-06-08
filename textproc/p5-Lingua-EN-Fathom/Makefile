# $NetBSD: Makefile,v 1.2 2016/06/08 19:24:29 wiz Exp $

DISTNAME=	Lingua-EN-Fathom-1.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~kimryan/Lingua-EN-Fathom-1.18/
COMMENT=	Measure readability of English text
LICENSE=	artistic AND gnu-gpl-v1

DEPENDS+=	p5-Lingua-EN-Syllable>=0:../../textproc/p5-Lingua-EN-Syllable

PERL5_PACKLIST=	auto/Lingua/EN/Fathom/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
