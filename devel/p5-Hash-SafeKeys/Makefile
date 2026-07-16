# $NetBSD: Makefile,v 1.4 2026/07/16 19:02:35 wiz Exp $

DISTNAME=		Hash-SafeKeys-0.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MO/MOB/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/dist/Hash-SafeKeys
COMMENT=		Perl5 module to get hash contents without resetting each iterator
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Hash/SafeKeys/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
