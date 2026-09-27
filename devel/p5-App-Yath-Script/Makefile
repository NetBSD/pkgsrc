# $NetBSD: Makefile,v 1.1 2026/09/27 13:16:12 wen Exp $

DISTNAME=		App-Yath-Script-2.000017
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/App-Yath-Script
COMMENT=		Script initialization and utility functions for Test2::Harness
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Getopt-Yath>=0:../../devel/p5-Getopt-Yath

USE_TOOLS+=		perl

PERL5_PACKLIST=		auto/App/Yath/Script/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
