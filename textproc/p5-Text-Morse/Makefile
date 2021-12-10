# $NetBSD: Makefile,v 1.1 2021/12/10 18:42:53 hubertf Exp $

DISTNAME=	Text-Morse-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Text::Morse
COMMENT=	Encoding and decoding Morse code

PERL5_PACKLIST=	auto/Text/Morse/.packlist
#USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
