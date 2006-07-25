# $NetBSD: Makefile,v 1.2 2006/07/25 15:34:34 joerg Exp $
#

DISTNAME=	Text-LevenshteinXS-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-LevenshteinXS
COMMENT=	XS implementation of the Levenshtein edit distance

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Text/LevenshteinXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
