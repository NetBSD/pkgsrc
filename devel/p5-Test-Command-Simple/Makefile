# $NetBSD: Makefile,v 1.13 2019/08/11 13:20:29 wiz Exp $

DISTNAME=		Test-Command-Simple-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Command-Simple
COMMENT=		Test external commands (nearly) as easily as loaded modules
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Command/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
