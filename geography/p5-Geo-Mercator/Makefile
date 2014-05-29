# $NetBSD: Makefile,v 1.7 2014/05/29 23:36:36 wiz Exp $
#

DISTNAME=		Geo-Mercator-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
SVR4_PKGNAME=		p5gme
CATEGORIES=		geography perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Geo-Mercator/
COMMENT=		Perl5 module computing Mercator Projection into meters

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geo/Mercator/.packlist

PREV_PKGPATH=		misc/p5-Geo-Mercator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
