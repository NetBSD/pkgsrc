# $NetBSD: Makefile,v 1.1.1.1 2005/10/16 17:48:02 heinz Exp $
#

DISTNAME=		IP-Country-2.20
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5icy
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/N/NW/NWETTERS/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IP-Country/
COMMENT=		Fast lookup of country codes from IP addresses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Geo-IP-[0-9]*:../../net/p5-Geo-IP
DEPENDS+=		p5-Geography-Countries>=1.3:../../misc/p5-Geography-Countries

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IP/Country/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
