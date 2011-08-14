# $NetBSD: Makefile,v 1.3 2011/08/14 12:48:49 obache Exp $
#

DISTNAME=	Geo-ShapeFile-2.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
