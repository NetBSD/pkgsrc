# $NetBSD: Makefile,v 1.10 2013/05/31 12:40:15 wiz Exp $

DISTNAME=	Devel-PartialDump-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-PartialDump/
COMMENT=	Perl 5 module to make partial dumps of data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean
# For test target
BUILD_DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/PartialDump/.packlist
REPLACE_PERL+=		lib/Devel/PartialDump.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
