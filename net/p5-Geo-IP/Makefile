# $NetBSD: Makefile,v 1.36 2019/06/30 20:16:25 nia Exp $

DISTNAME=	Geo-IP-1.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.maxmind.com/geoip/api/perl.shtml
HOMEPAGE=	https://metacpan.org/release/Geo-IP
COMMENT=	Gets country name by IP or hostname
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Geo/IP/.packlist
MAKE_PARAMS+=	LIBS="-L${PREFIX:Q}/lib -Wl,-R${PREFIX:Q}/lib"
MAKE_PARAMS+=	INC="-I${PREFIX:Q}/include"

.include "../../lang/perl5/module.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
