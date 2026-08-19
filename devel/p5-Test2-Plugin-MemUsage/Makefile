# $NetBSD: Makefile,v 1.3 2026/08/19 06:34:51 wen Exp $

DISTNAME=		Test2-Plugin-MemUsage-0.002006
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test2-Plugin-MemUsage
COMMENT=		Collect and display memory usage information
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test2/Plugin/MemUsage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
