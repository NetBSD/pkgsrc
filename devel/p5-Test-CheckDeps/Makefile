# $NetBSD: Makefile,v 1.4 2013/05/27 14:47:54 wen Exp $
#

DISTNAME=	Test-CheckDeps-0.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-CheckDeps/
COMMENT=	Perl 5 module to check for presence of dependencies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CPAN-Meta>=2.12092:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-CPAN-Meta-Check-[0-9]*:../../devel/p5-CPAN-Meta-Check

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/CheckDeps/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
