# $NetBSD: Makefile,v 1.3 2012/10/31 11:19:03 asau Exp $
#

DISTNAME=	Test-CheckDeps-0.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-CheckDeps/
COMMENT=	Perl 5 module to check for presence of dependencies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.14.0,p5-CPAN-Meta-[0-9]*}:../../devel/p5-CPAN-Meta
DEPENDS+=	p5-CPAN-Meta-Check-[0-9]*:../../devel/p5-CPAN-Meta-Check

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/CheckDeps/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
