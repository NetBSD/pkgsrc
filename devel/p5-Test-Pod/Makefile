# $NetBSD: Makefile,v 1.43 2022/06/28 11:33:28 wiz Exp $

DISTNAME=		Test-Pod-1.52
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Pod
COMMENT=		Perl5 module to check for POD errors in files
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		{perl>=5.10.1,p5-Pod-Simple>=3.07}:../../textproc/p5-Pod-Simple
#DEPENDS+=		{p5-Test-Simple>=0.70,perl>=5.8.9}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
