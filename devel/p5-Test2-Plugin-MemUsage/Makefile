# $NetBSD: Makefile,v 1.1 2025/11/15 06:58:00 wen Exp $

DISTNAME=		Test2-Plugin-MemUsage-0.002003
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
