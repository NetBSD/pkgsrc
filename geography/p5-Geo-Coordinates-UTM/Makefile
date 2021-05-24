# $NetBSD: Makefile,v 1.17 2021/05/24 19:52:18 wiz Exp $
#

DISTNAME=		Geo-Coordinates-UTM-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		geography perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Geo-Coordinates-UTM
COMMENT=		Perl extension for Latitude Longitude conversions
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geo/Coordinates/UTM/.packlist

PREV_PKGPATH=		misc/p5-Geo-Coordinates-UTM

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
