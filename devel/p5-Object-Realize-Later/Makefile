# $NetBSD: Makefile,v 1.35 2026/10/29 11:26:38 wen Exp $

DISTNAME=	Object-Realize-Later-4.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKOV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Object-Realize-Later
COMMENT=	Delayed creation of objects
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/Object/Realize/Later/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
