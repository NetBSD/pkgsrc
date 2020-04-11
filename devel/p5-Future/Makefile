# $NetBSD: Makefile,v 1.21 2020/04/11 12:18:56 mef Exp $

DISTNAME=	Future-0.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Future
COMMENT=	Represent an operation awaiting completion
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Identity-[0-9]*:../../devel/p5-Test-Identity
TEST_DEPENDS+=	p5-Test-Refcount-[0-9]*:../../devel/p5-Test-Refcount

USE_LANGUAGES=		#empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Future/.packlist
PERL5_REQD+=		5.10.1	# Test::More >= 0.88

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
