# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:35 tv Exp $

DISTNAME=		Test-Pod-1.20
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5tp
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Pod/
COMMENT=		Perl5 module to check for POD errors in files

DEPENDS+=		p5-Pod-Simple>=3.02nb1:../../textproc/p5-Pod-Simple
# These are only for the 'test' target.
BUILD_DEPENDS+=		p5-Test-Builder-Tester-[0-9]*:../../devel/p5-Test-Builder-Tester

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
