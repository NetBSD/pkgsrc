# $NetBSD: Makefile,v 1.1 2020/09/02 23:42:06 mef Exp $

DISTNAME=	Test-Alien-CPP-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/P/PL/PLICEASE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/P/PL/PLICEASE/
COMMENT=	Testing tools for Alien modules for projects that use C++
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-ExtUtils-CppGuess-[0-9]*:../../devel/p5-ExtUtils-CppGuess

PERL5_PACKLIST=	auto/Test/Alien/CPP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
