# $NetBSD: Makefile,v 1.21 2021/05/24 19:51:40 wiz Exp $

DISTNAME=	Test-CheckDeps-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-CheckDeps
COMMENT=	Perl 5 module to check for presence of dependencies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CPAN-Meta-Check>=0.007:../../devel/p5-CPAN-Meta-Check

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/CheckDeps/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
