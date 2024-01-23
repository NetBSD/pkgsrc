# $NetBSD: Makefile,v 1.7 2024/01/23 13:33:39 mef Exp $

DISTNAME=	Test-Alien-CPP-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::Alien::CPP
COMMENT=	Testing tools for Alien modules for projects that use C++
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-ExtUtils-CppGuess-[0-9]*:../../devel/p5-ExtUtils-CppGuess

# make test requires c++
USE_LANGUAGES+=	c++

PERL5_PACKLIST=	auto/Test/Alien/CPP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
