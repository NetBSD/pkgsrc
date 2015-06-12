# $NetBSD: Makefile,v 1.3 2015/06/12 10:48:25 wiz Exp $

DISTNAME=	Benchmark-Timer-0.7102
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Benchmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Benchmark-Timer/
COMMENT=	Benchmarking with statistical confidence
#LICENSE=	GPL but not clear which version

DEPENDS+=	p5-Statistics-TTest-[0-9]*:../../math/p5-Statistics-TTest

PERL5_PACKLIST=		auto/Benchmark/Timer/.packlist
REPLACE_PERL=		delta.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
