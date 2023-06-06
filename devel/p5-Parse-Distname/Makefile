# $NetBSD: Makefile,v 1.4 2023/06/06 12:41:02 riastradh Exp $

DISTNAME=	Parse-Distname-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IS/ISHIGAKI/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parse-Distname
COMMENT=	Parse a distribution name
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Module-CPANfile-[0-9]*:../../devel/p5-Module-CPANfile
TOOL_DEPENDS+=	p5-ExtUtils-MakeMaker-CPANfile-[0-9]*:../../devel/p5-ExtUtils-MakeMaker-CPANfile
TEST_DEPENDS+=	p5-Test-Differences>=0:../../devel/p5-Test-Differences
TEST_DEPENDS+=	p5-Test-UseAllModules>=0.17:../../devel/p5-Test-UseAllModules

PERL5_PACKLIST=	auto/Parse/Distname/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
