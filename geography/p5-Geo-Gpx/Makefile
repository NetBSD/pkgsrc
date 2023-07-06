# $NetBSD: Makefile,v 1.13 2023/07/06 09:40:36 wiz Exp $
#

DISTNAME=	Geo-Gpx-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Geo-Gpx/changes
COMMENT=	Geo::Gpx - Create and parse GPX files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Geo/Gpx/.packlist

MAKE_PARAMS+=		--skipdeps

DEPENDS+=	p5-DateTime-Format-ISO8601>=0.0800:../../time/p5-DateTime-Format-ISO8601
DEPENDS+=	p5-HTML-Parser>=3.71:../../www/p5-HTML-Parser
DEPENDS+=	p5-XML-Descent>=1.04:../../textproc/p5-XML-Descent
DEPENDS+=	p5-Geo-Coordinates-Transform>=0:../../geography/p5-Geo-Coordinates-Transform

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
