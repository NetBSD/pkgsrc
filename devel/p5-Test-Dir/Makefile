# $NetBSD: Makefile,v 1.10 2019/06/30 20:15:51 nia Exp $
#

DISTNAME=		Test-Dir-1.16
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Dir
COMMENT=		Test directory attributes
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Dir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
