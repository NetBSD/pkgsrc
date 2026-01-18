# $NetBSD: Makefile,v 1.1 2026/01/18 08:28:27 wen Exp $

DISTNAME=		Test2-Plugin-IOEvents-0.001001
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test2-Plugin-IOEvents
COMMENT=		Turn STDOUT and STDERR into Test2 events
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test2/Plugin/IOEvents/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
