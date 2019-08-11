# $NetBSD: Makefile,v 1.99 2019/08/11 13:20:36 wiz Exp $

DISTNAME=		Test-Simple-1.302164
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Simple
COMMENT=		Perl5 module with a simple framework for writing tests
LICENSE=		${PERL5_LICENSE}

CONFLICTS+=		p5-Test-Tester-[0-9]*
CONFLICTS+=		p5-Test-use-ok-[0-9]*

PERL5_PACKLIST=		auto/Test/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
