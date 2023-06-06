# $NetBSD: Makefile,v 1.25 2023/06/06 12:40:48 riastradh Exp $

DISTNAME=	ExtUtils-CppGuess-0.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SMUELLER/ExtUtils-CppGuess-0.07
COMMENT=	Perl5 module for guess C++ compiler and flags
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

LDFLAGS+=	-lstdc++
USE_LANGUAGES+=	c c++

PERL5_PACKLIST=		auto/ExtUtils/CppGuess/.packlist
# one test failure as of 0.12


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
