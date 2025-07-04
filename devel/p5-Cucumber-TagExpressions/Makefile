# $NetBSD: Makefile,v 1.8 2025/07/04 08:45:28 wiz Exp $

DISTNAME=	Cucumber-TagExpressions-6.2.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
