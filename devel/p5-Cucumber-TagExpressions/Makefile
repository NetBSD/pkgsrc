# $NetBSD: Makefile,v 1.2 2023/10/13 18:29:50 schmonz Exp $

DISTNAME=	Cucumber-TagExpressions-6.0.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CU/CUKEBOT/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Cucumber-TagExpressions
COMMENT=	Cucumber tag expression parser
LICENSE=	mit

DEPENDS+=	p5-Moo>=0:../../devel/p5-Moo

PERL5_PACKLIST=	auto/Cucumber/TagExpressions/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
