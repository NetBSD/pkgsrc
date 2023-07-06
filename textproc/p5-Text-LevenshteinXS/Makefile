# $NetBSD: Makefile,v 1.22 2023/07/06 09:41:53 wiz Exp $
#

DISTNAME=	Text-LevenshteinXS-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-LevenshteinXS
COMMENT=	XS implementation of the Levenshtein edit distance

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Text/LevenshteinXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
