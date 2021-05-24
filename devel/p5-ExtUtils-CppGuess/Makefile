# $NetBSD: Makefile,v 1.21 2021/05/24 19:50:37 wiz Exp $

DISTNAME=	ExtUtils-CppGuess-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SMUELLER/ExtUtils-CppGuess-0.07
COMMENT=	Perl5 module for guess C++ compiler and flags
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

LDFLAGS+=	-lstdc++
USE_LANGUAGES+=	c c++

PERL5_PACKLIST=		auto/ExtUtils/CppGuess/.packlist
# one test failure as of 0.12


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
