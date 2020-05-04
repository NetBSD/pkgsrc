# $NetBSD: Makefile,v 1.28 2020/05/04 02:13:54 mef Exp $

DISTNAME=	Algorithm-Dependency-1.112
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Dependency
COMMENT=	Algorithmic framework for implementing dependency tree
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Util>=0.31:../../devel/p5-Params-Util
TEST_DEPENDS+=	p5-Test-ClassAPI>=0.6:../../devel/p5-Test-ClassAPI

PERL5_PACKLIST=		auto/Algorithm/Dependency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
