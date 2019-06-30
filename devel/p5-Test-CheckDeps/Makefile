# $NetBSD: Makefile,v 1.17 2019/06/30 20:15:50 nia Exp $
#

DISTNAME=	Test-CheckDeps-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-CheckDeps
COMMENT=	Perl 5 module to check for presence of dependencies
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.18.0,p5-CPAN-Meta>=2.120920}:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-CPAN-Meta-Check>=0.007:../../devel/p5-CPAN-Meta-Check

# make test
BUILD_DEPENDS+=	p5-Module-Metadata>=1.000023:../../devel/p5-Module-Metadata

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/CheckDeps/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
