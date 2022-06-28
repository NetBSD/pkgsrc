# $NetBSD: Makefile,v 1.26 2022/06/28 11:32:17 wiz Exp $

DISTNAME=	Devel-PartialDump-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-PartialDump
COMMENT=	Perl 5 module to make partial dumps of data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
TEST_DEPENDS+=	p5-Class-Tiny-[0-9]*:../../devel/p5-Class-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/PartialDump/.packlist
REPLACE_PERL+=		lib/Devel/PartialDump.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
