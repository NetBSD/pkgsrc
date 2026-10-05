# $NetBSD: Makefile,v 1.3 2026/10/05 02:33:14 wen Exp $

DISTNAME=		Long-Jump-0.000005
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Long-Jump
COMMENT=		Mechanism for returning to a specific point from a deeply nested stack
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Importer>=0:../../devel/p5-Importer

PERL5_PACKLIST=		auto/Long/Jump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
