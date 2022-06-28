# $NetBSD: Makefile,v 1.5 2022/06/28 11:33:20 wiz Exp $

DISTNAME=	Test-Alien-CPP-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::Alien::CPP
COMMENT=	Testing tools for Alien modules for projects that use C++
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-ExtUtils-CppGuess-[0-9]*:../../devel/p5-ExtUtils-CppGuess

PERL5_PACKLIST=	auto/Test/Alien/CPP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
