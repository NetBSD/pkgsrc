# $NetBSD: Makefile,v 1.4 2013/11/24 10:02:40 wiz Exp $

DISTNAME=		Test-More-Behaviour-1.0.1
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-More-Behaviour/
COMMENT=		BDD module for Perl modeled after Rspec
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		p5-Term-ANSIColor>=3.00:../../devel/p5-Term-ANSIColor
DEPENDS+=		p5-version-[0-9]*:../../devel/p5-version
BUILD_DEPENDS+=		p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture

PERL5_PACKLIST=		auto/Test/More/Behaviour/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
