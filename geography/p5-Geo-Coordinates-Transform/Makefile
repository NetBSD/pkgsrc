# $NetBSD: Makefile,v 1.1 2023/06/30 09:55:10 wen Exp $

DISTNAME=	Geo-Coordinates-Transform-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Geo-Coordinates-Transform
COMMENT=	Transform Lat/Long between various different coordinate functions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Geo/Coordinates/Transform/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
