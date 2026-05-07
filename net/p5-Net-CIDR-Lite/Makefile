# $NetBSD: Makefile,v 1.33.6.1 2026/05/07 18:41:54 maya Exp $

DISTNAME=		Net-CIDR-Lite-0.23
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/S/ST/STIGTSP/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Net-CIDR-Lite
COMMENT=		Perl extension for merging IPv4/v6 CIDR addresses
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/CIDR/Lite/.packlist
USE_LANGUAGES=		# empty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
