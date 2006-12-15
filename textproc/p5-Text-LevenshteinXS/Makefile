# $NetBSD: Makefile,v 1.3 2006/12/15 14:34:21 wiz Exp $
#

DISTNAME=	Text-LevenshteinXS-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-LevenshteinXS
COMMENT=	XS implementation of the Levenshtein edit distance

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Text/LevenshteinXS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
