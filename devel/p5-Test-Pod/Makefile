# $NetBSD: Makefile,v 1.36 2017/06/05 14:23:45 ryoon Exp $

DISTNAME=		Test-Pod-1.51
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Pod/
COMMENT=		Perl5 module to check for POD errors in files
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.10.1,p5-Pod-Simple>=3.07}:../../textproc/p5-Pod-Simple
#DEPENDS+=		{p5-Test-Simple>=0.70,perl>=5.8.9}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
