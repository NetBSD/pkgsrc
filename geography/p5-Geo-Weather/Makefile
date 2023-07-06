# $NetBSD: Makefile,v 1.17 2023/07/06 09:40:36 wiz Exp $
#

DISTNAME=		Geo-Weather-1.41
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		geography perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Geo-Weather
COMMENT=		Perl5 weather retrieval module

DEPENDS+=		p5-libwww>=5.803nb1:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geo/Weather/.packlist

PREV_PKGPATH=		misc/p5-Geo-Weather

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
