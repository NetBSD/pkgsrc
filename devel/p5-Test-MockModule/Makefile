# $NetBSD: Makefile,v 1.22 2018/09/02 07:25:37 wiz Exp $

DISTNAME=	Test-MockModule-v0.170.0
PKGNAME=	p5-${DISTNAME:S/v0/0/}
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-MockModule/
COMMENT=	Perl 5 module to override subroutines in a module for unit testing
LICENSE=	gnu-gpl-v3

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Test/MockModule/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
