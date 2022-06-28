# $NetBSD: Makefile,v 1.18 2022/06/28 11:33:57 wiz Exp $
#

DISTNAME=		Geo-Coordinates-UTM-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
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
