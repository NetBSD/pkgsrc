# $NetBSD: Makefile,v 1.9 2024/07/30 06:49:41 wen Exp $

DISTNAME=	Test-Alien-CPP-1.03
PKGNAME=	p5-${DISTNAME}
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
