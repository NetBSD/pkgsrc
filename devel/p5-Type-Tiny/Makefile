# $NetBSD: Makefile,v 1.17 2020/04/18 12:17:18 mef Exp $

DISTNAME=	Type-Tiny-1.010001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Type-Tiny
COMMENT=	Tiny, yet Moo(se)-compatible type constraint
LICENSE=	gnu-gpl-v1 OR artistic

DEPENDS+=	p5-Exporter-Tiny>=1.000000:../../devel/p5-Exporter-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Type/Tiny/.packlist

TEST_DEPENDS+=	p5-Class-InsideOut-[0-9]*:../../devel/p5-Class-InsideOut
TEST_DEPENDS+=	p5-Devel-Hide-[0-9]*:../../devel/p5-Devel-Hide
TEST_DEPENDS+=	p5-Devel-LexAlias-[0-9]*:../../devel/p5-Devel-LexAlias
TEST_DEPENDS+=	p5-Function-Parameters-[0-9]*:../../devel/p5-Function-Parameters
TEST_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
TEST_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
TEST_DEPENDS+=	p5-MooseX-Getopt-[0-9]*:../../devel/p5-MooseX-Getopt
TEST_DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
TEST_DEPENDS+=	p5-MooseX-Types-Common-[0-9]*:../../devel/p5-MooseX-Types-Common
TEST_DEPENDS+=	p5-Mouse-[0-9]*:../../devel/p5-Mouse
TEST_DEPENDS+=	p5-Object-Accessor-[0-9]*:../../devel/p5-Object-Accessor
TEST_DEPENDS+=	p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle

# and many more

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
