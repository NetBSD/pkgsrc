# $NetBSD: Makefile,v 1.13 2019/03/25 07:01:53 wiz Exp $

DISTNAME=	ExtUtils-CppGuess-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~smueller/ExtUtils-CppGuess/
COMMENT=	Perl5 module for guess C++ compiler and flags
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=		auto/ExtUtils/CppGuess/.packlist
# one test failure as of 0.12
# https://github.com/tsee/extutils-cppguess/issues/17

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
