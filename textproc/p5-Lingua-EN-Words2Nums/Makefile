# $NetBSD: Makefile,v 1.12 2022/06/28 11:36:18 wiz Exp $

DISTNAME=	Lingua-EN-Words2Nums-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
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
