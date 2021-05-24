# $NetBSD: Makefile,v 1.11 2021/05/24 19:52:18 wiz Exp $
#

DISTNAME=	Geo-Ellipsoid-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/Geo-Ellipsoid
COMMENT=	Longitude and latitude calculations using an ellipsoid model
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Number-Delta>=0.16:../../math/p5-Test-Number-Delta

PERL5_PACKLIST=	auto/Geo/Ellipsoid/.packlist

MAKE_PARAMS+=	--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
