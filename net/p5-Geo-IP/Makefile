# $NetBSD: Makefile,v 1.3 2004/11/12 00:29:49 seb Exp $
#

DISTNAME=	Geo-IP-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/geoip/api/perl.shtml
COMMENT=	Gets country name by IP or hostname

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Geo/IP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
