# $NetBSD: Makefile,v 1.14 2008/07/17 15:17:19 heinz Exp $
#

DISTNAME=	Geo-IP-1.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/geoip/api/perl.shtml
COMMENT=	Gets country name by IP or hostname

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Geo/IP/.packlist
MAKE_PARAMS+=	LIBS="-L${PREFIX:Q}/lib -Wl,-R${PREFIX:Q}/lib"
MAKE_PARAMS+=	INC="-I${PREFIX:Q}/include"

.include "../../lang/perl5/module.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
