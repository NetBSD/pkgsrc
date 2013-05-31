# $NetBSD: Makefile,v 1.6 2013/05/31 12:41:04 wiz Exp $
#

DISTNAME=		Geo-Weather-1.41
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		geography perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Geo-Weather/
COMMENT=		Perl5 weather retrieval module

DEPENDS+=		p5-libwww>=5.803nb1:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geo/Weather/.packlist

PREV_PKGPATH=		misc/p5-Geo-Weather

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
