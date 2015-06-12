# $NetBSD: Makefile,v 1.9 2015/06/12 10:50:08 wiz Exp $
#

DISTNAME=	Geo-ShapeFile-2.60
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jasonk/Geo-ShapeFile-2.52/lib/Geo/ShapeFile.pm
COMMENT=	Perl extension for handling ESRI GIS Shapefiles
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Geo/ShapeFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
