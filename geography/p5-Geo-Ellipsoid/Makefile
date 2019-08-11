# $NetBSD: Makefile,v 1.8 2019/08/11 13:21:05 wiz Exp $
#

DISTNAME=	Geo-Ellipsoid-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/PJACKLAM/Geo-Ellipsoid-1.13/lib/Geo/Ellipsoid.pm
COMMENT=	Longitude and latitude calculations using an ellipsoid model
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Number-Delta>=0.16:../../math/p5-Test-Number-Delta

PERL5_PACKLIST=	auto/Geo/Ellipsoid/.packlist

MAKE_PARAMS+=	--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
