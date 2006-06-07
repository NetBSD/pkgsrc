# $NetBSD: Makefile,v 1.1.1.1 2006/06/07 12:00:59 abs Exp $
#

DISTNAME=	IO-Prompt-v0.99.4
PKGNAME=	p5-${DISTNAME:S:-v:-:}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~dconway/IO-Prompt/
COMMENT=	Interactively prompt for user input

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Prompt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
