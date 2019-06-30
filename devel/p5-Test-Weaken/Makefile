# $NetBSD: Makefile,v 1.17 2019/06/30 20:15:57 nia Exp $
#

DISTNAME=		Test-Weaken-3.022000
PKGNAME=		p5-${DISTNAME:S/020000/020.000/}
PKGREVISION=		6
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Weaken
COMMENT=		Test that freed memory objects were, indeed, freed
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Weaken/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
