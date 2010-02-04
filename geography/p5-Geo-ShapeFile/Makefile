# $NetBSD: Makefile,v 1.1.1.1 2010/02/04 09:52:04 wiz Exp $
#

DISTNAME=	Geo-ShapeFile-2.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/~jasonk/Geo-ShapeFile-2.52/lib/Geo/ShapeFile.pm
COMMENT=	Perl extension for handling ESRI GIS Shapefiles
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Geo/ShapeFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
