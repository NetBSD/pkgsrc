# $NetBSD: Makefile,v 1.9 2019/06/30 20:16:50 nia Exp $

DISTNAME=	Lingua-EN-Number-IsOrdinal-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-EN-Number-IsOrdinal
COMMENT=	Perl module to detect if English number is ordinal or cardinal
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lingua-EN-FindNumber-[0-9]*:../../textproc/p5-Lingua-EN-FindNumber

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Lingua/EN/Number/IsOrdinal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: also package Lingua-DE-Sentence, Lingua-HE-Sentence
