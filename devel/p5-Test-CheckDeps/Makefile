# $NetBSD: Makefile,v 1.22 2022/06/28 11:33:21 wiz Exp $

DISTNAME=	Test-CheckDeps-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
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
