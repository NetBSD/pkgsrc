# $NetBSD: Makefile,v 1.21 2019/08/11 13:20:37 wiz Exp $
#

DISTNAME=		Test-Taint-1.06
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Taint
COMMENT=		Tools to test taintedness
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Test/Taint/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
