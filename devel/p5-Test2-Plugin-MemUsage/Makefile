# $NetBSD: Makefile,v 1.2 2026/07/16 19:03:39 wiz Exp $

DISTNAME=		Test2-Plugin-MemUsage-0.002003
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test2-Plugin-MemUsage
COMMENT=		Collect and display memory usage information
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test2/Plugin/MemUsage/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
