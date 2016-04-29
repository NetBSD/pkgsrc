# $NetBSD: Makefile,v 1.10 2016/04/29 12:54:10 mef Exp $
#

DISTNAME=	IO-Prompter-0.004014
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Prompter/
COMMENT=	Prompt for, read, vet, chomp, and encapsulate input
LICENSE=	${PERL5_LICENSE}

PERL5_REQD+=	5.10

DEPENDS+=	p5-Contextual-Return-[0-9]*:../../devel/p5-Contextual-Return

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Prompter/.packlist

PERL5_MODULE_TYPE=	MakeMaker

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
