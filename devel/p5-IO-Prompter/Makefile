# $NetBSD: Makefile,v 1.1 2013/03/11 13:11:09 obache Exp $
#

DISTNAME=	IO-Prompter-0.004003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

HOMEPAGE=	http://search.cpan.org/dist/IO-Prompter/
COMMENT=	Prompt for, read, vet, chomp, and encapsulate input
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_REQD+=	5.10

DEPENDS+=	p5-Contextual-Return-[0-9]*:../../devel/p5-Contextual-Return

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Prompter/.packlist

PERL5_MODULE_TYPE=	MakeMaker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
