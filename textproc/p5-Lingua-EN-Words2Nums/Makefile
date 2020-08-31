# $NetBSD: Makefile,v 1.10 2020/08/31 18:11:49 wiz Exp $

DISTNAME=	Lingua-EN-Words2Nums-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-EN-Words2Nums
COMMENT=	Perl module to convert English text to numbers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Lingua/EN/Words2Nums/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: also package Lingua-DE-Sentence, Lingua-HE-Sentence
