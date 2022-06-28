# $NetBSD: Makefile,v 1.25 2022/06/28 11:33:30 wiz Exp $
#

DISTNAME=		Test-Taint-1.08
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Taint
COMMENT=		Tools to test taintedness
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Taint/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
