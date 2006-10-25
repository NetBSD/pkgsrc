# $NetBSD: Makefile,v 1.14 2006/10/25 09:39:54 obache Exp $

DISTNAME=		Test-Pod-1.26
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tp
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Pod/
COMMENT=		Perl5 module to check for POD errors in files

DEPENDS+=		p5-Pod-Simple>=3.02nb1:../../textproc/p5-Pod-Simple
DEPENDS+=		{p5-Test-Simple>=0.62,perl>=5.8.8}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
