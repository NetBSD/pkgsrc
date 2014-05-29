# $NetBSD: Makefile,v 1.6 2014/05/29 23:36:20 wiz Exp $

DISTNAME=		Test-Command-Simple-0.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Command-Simple/
COMMENT=		Test external commands (nearly) as easily as loaded modules
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Command/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
