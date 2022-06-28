# $NetBSD: Makefile,v 1.11 2022/06/28 11:33:32 wiz Exp $
#

DISTNAME=		Test-utf8-1.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-utf8
COMMENT=		Handy UTF-8 tests
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/utf8/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
