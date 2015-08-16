# $NetBSD: Makefile,v 1.4 2015/08/16 02:21:45 mef Exp $

DISTNAME=	Benchmark-Timer-0.7107
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Benchmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Benchmark-Timer/
COMMENT=	Benchmarking with statistical confidence
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Statistics-TTest-[0-9]*:../../math/p5-Statistics-TTest
# for make test
BUILD_DEPENDS+=	p5-URI-Escape-XS-[0-9]*:../../www/p5-URI-Escape-XS

PERL5_PACKLIST=		auto/Benchmark/Timer/.packlist
REPLACE_PERL=		delta.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
