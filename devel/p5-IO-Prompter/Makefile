# $NetBSD: Makefile,v 1.22 2024/11/16 12:04:25 wiz Exp $
#

DISTNAME=	IO-Prompter-0.005001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Prompter
COMMENT=	Prompt for, read, vet, chomp, and encapsulate input
LICENSE=	${PERL5_LICENSE}

PERL5_REQD+=	5.10

DEPENDS+=	p5-Contextual-Return-[0-9]*:../../devel/p5-Contextual-Return

TEST_DEPENDS+=	p5-match-simple-[0-9]*:../../devel/p5-match-simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Prompter/.packlist

PERL5_MODULE_TYPE=	MakeMaker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
