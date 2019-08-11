# $NetBSD: Makefile,v 1.2 2019/08/11 13:22:15 wiz Exp $

DISTNAME=	MaxMind-DB-Common-0.040001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MAXMIND/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MaxMind-DB-Common
COMMENT=	Code shared by the MaxMind DB reader and writer modules
LICENSE=	artistic-2.0

DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-Data-Dumper-Concise>=0:../../devel/p5-Data-Dumper-Concise
DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime
DEPENDS+=	p5-List-AllUtils>=0:../../devel/p5-List-AllUtils
DEPENDS+=	p5-Math-BigInt>=0:../../math/p5-Math-BigInt
DEPENDS+=	p5-Moo>=0:../../devel/p5-Moo
DEPENDS+=	p5-MooX-StrictConstructor>=0:../../devel/p5-MooX-StrictConstructor
DEPENDS+=	p5-Sub-Quote>=0:../../devel/p5-Sub-Quote
DEPENDS+=	p5-autodie>=0:../../devel/p5-autodie
DEPENDS+=	p5-namespace-autoclean>=0:../../devel/p5-namespace-autoclean

PERL5_PACKLIST=	auto/MaxMind/DB/Common/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
