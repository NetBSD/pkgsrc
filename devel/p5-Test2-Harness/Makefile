# $NetBSD: Makefile,v 1.2 2026/07/16 19:03:39 wiz Exp $

DISTNAME=		Test2-Harness-1.000161
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test2-Harness
COMMENT=		Test2 Harness designed for the Test2 event system
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Data-UUID>=0:../../devel/p5-Data-UUID
DEPENDS+=		p5-Importer>=0.025:../../devel/p5-Importer
DEPENDS+=		p5-Long-Jump>=0.000001:../../devel/p5-Long-Jump
DEPENDS+=		p5-Scope-Guard>=0:../../devel/p5-Scope-Guard
DEPENDS+=		p5-Term-Table>=0.015:../../devel/p5-Term-Table
DEPENDS+=		p5-Test2-Plugin-MemUsage>=0.002002:../../devel/p5-Test2-Plugin-MemUsage
DEPENDS+=		p5-Test2-Plugin-UUID>=0.002001:../../devel/p5-Test2-Plugin-UUID
DEPENDS+=		p5-YAML-Tiny>=0:../../textproc/p5-YAML-Tiny
DEPENDS+=		p5-goto-file>=0.005:../../devel/p5-goto-file

USE_TOOLS+=		perl

PERL5_PACKLIST=		auto/Test2/Harness/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
