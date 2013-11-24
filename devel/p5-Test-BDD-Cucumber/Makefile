# $NetBSD: Makefile,v 1.6 2013/11/24 10:02:40 wiz Exp $

DISTNAME=		Test-BDD-Cucumber-0.15
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-BDD-Cucumber/
COMMENT=		Feature-complete Cucumber-style testing in Perl
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=		p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=		p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=		p5-FindBin-libs-[0-9]*:../../devel/p5-FindBin-libs
DEPENDS+=		p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=		p5-Method-Signatures-[0-9]*:../../devel/p5-Method-Signatures
DEPENDS+=		p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=		p5-Ouch-[0-9]*:../../devel/p5-Ouch
DEPENDS+=		p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
#DEPENDS+=		p5-Storable-[0-9]*:../../devel/p5-Storable
#DEPENDS+=		p5-Term-ANSIColor>=3.00:../../devel/p5-Term-ANSIColor
DEPENDS+=		p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
DEPENDS+=		p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

REPLACE_PERL+=		bin/pherkin
PERL5_PACKLIST=		auto/Test/BDD/Cucumber/.packlist

post-extract:
	chmod -x ${WRKSRC}/lib/Test/BDD/Cucumber/StepFile.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
