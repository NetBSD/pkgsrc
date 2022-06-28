# $NetBSD: Makefile,v 1.3 2022/06/28 11:33:02 wiz Exp $

DISTNAME=	Parse-Distname-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IS/ISHIGAKI/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parse-Distname
COMMENT=	Parse a distribution name
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Module-CPANfile-[0-9]*:../../devel/p5-Module-CPANfile
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker-CPANfile-[0-9]*:../../devel/p5-ExtUtils-MakeMaker-CPANfile
TEST_DEPENDS+=	p5-Test-Differences>=0:../../devel/p5-Test-Differences
TEST_DEPENDS+=	p5-Test-UseAllModules>=0.17:../../devel/p5-Test-UseAllModules

PERL5_PACKLIST=	auto/Parse/Distname/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
