# $NetBSD: Makefile,v 1.17 2025/07/04 08:48:15 wiz Exp $

DISTNAME=	Lingua-EN-Fathom-1.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-EN-Fathom
COMMENT=	Measure readability of English text
LICENSE=	artistic AND gnu-gpl-v1

DEPENDS+=	p5-Lingua-EN-Syllable>=0.28:../../textproc/p5-Lingua-EN-Syllable
DEPENDS+=	p5-Lingua-EN-Sentence>=0.28:../../textproc/p5-Lingua-EN-Sentence

PERL5_PACKLIST=	auto/Lingua/EN/Fathom/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
