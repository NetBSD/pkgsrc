# $NetBSD: Makefile,v 1.41 2026/10/21 05:03:40 wiz Exp $

DISTNAME=		Mozilla-CA-20261020
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LW/LWP/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Mozilla-CA
COMMENT=		Mozilla's CA cert bundle for Perl
LICENSE=		mpl-2.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Mozilla/CA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
