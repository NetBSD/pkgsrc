# $NetBSD: Makefile,v 1.1 2026/09/27 13:07:27 wen Exp $

DISTNAME=		Getopt-Yath-2.000011
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Getopt-Yath
COMMENT=		Option processing yath style
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Cpanel-JSON-XS>=0:../../converters/p5-Cpanel-JSON-XS
DEPENDS+=		p5-Importer>=0:../../devel/p5-Importer
DEPENDS+=		p5-Term-Table>=0:../../devel/p5-Term-Table

USE_TOOLS+=		perl

PERL5_PACKLIST=		auto/Getopt/Yath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
