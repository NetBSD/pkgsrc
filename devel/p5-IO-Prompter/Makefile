# $NetBSD: Makefile,v 1.25 2025/09/21 02:20:27 wen Exp $
#

DISTNAME=	IO-Prompter-0.005004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Prompter
COMMENT=	Prompt for, read, vet, chomp, and encapsulate input
LICENSE=	${PERL5_LICENSE}

PERL5_REQD+=	5.10

DEPENDS+=	p5-Contextual-Return-[0-9]*:../../devel/p5-Contextual-Return
DEPENDS+=	p5-Exporter-Tiny>=0:../../devel/p5-Exporter-Tiny

TEST_DEPENDS+=	p5-match-simple-[0-9]*:../../devel/p5-match-simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Prompter/.packlist

PERL5_MODULE_TYPE=	MakeMaker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
