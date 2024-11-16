# $NetBSD: Makefile,v 1.13 2024/11/16 12:05:25 wiz Exp $
#

DISTNAME=		Test-utf8-1.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-utf8
COMMENT=		Handy UTF-8 tests
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/utf8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
