# $NetBSD: Makefile,v 1.23 2023/06/30 09:39:26 wen Exp $

DISTNAME=	Geo-ShapeFile-3.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Geo-ShapeFile
COMMENT=	Perl extension for handling ESRI GIS Shapefiles
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Tree-R>=0:../../devel/p5-Tree-R
DEPENDS+=	p5-autovivification-[0-9]*:../../devel/p5-autovivification
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-rlib-[0-9]*:../../devel/p5-rlib

PERL5_PACKLIST=	auto/Geo/ShapeFile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
