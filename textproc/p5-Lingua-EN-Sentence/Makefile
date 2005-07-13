# $NetBSD: Makefile,v 1.2 2005/07/13 18:01:41 jlam Exp $

DISTNAME=	Lingua-EN-Sentence-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-EN-Sentence/
COMMENT=	Perl module for splitting English text into sentences

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Lingua/EN/Sentence/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: also package Lingua-DE-Sentence, Lingua-HE-Sentence
