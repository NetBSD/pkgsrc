# $NetBSD: Makefile,v 1.1 2025/11/15 03:58:12 wen Exp $

DISTNAME=		Test2-Plugin-UUID-0.002010
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test2-Plugin-UUID
COMMENT=		Use REAL UUIDs in Test2
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-UUID-Tiny>=0:../../devel/p5-UUID-Tiny

PERL5_PACKLIST=		auto/Test2/Plugin/UUID/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
