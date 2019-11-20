# $NetBSD: Makefile,v 1.25 2019/11/20 13:26:15 mef Exp $

DISTNAME=		Test-Memory-Cycle-1.06
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Memory-Cycle
COMMENT=		Check for memory leaks and circular memory references
LICENSE=		artistic-2.0

DEPENDS+=		p5-Devel-Cycle-[0-9]*:../../devel/p5-Devel-Cycle

TEST_DEPENDS+=		p5-CGI-[0-9]*:../../www/p5-CGI
TEST_DEPENDS+=		p5-Test-Pod-Coverage>=1.04:../../devel/p5-Test-Pod-Coverage
TEST_DEPENDS+=		p5-Test-Pod>=1.14:../../devel/p5-Test-Pod

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Memory/Cycle/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
