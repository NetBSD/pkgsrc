# $NetBSD: Makefile,v 1.18 2019/08/11 13:20:39 wiz Exp $
#

DISTNAME=		Test-Weaken-3.022000
PKGNAME=		p5-${DISTNAME:S/020000/020.000/}
PKGREVISION=		7
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
