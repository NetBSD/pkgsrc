# $NetBSD: Makefile,v 1.15 2019/08/11 13:21:06 wiz Exp $
#

DISTNAME=		Geo-Mercator-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		geography perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Geo-Mercator
COMMENT=		Perl5 module computing Mercator Projection into meters

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geo/Mercator/.packlist

PREV_PKGPATH=		misc/p5-Geo-Mercator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
