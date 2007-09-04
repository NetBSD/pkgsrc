# $NetBSD: Makefile,v 1.8 2007/09/04 19:55:40 joerg Exp $

DISTNAME=	Chart-ThreeD-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5c3d
PKGREVISION=	4
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Chart-ThreeD/
COMMENT=	Three-Dimentional pie chart plotting

DEPENDS+=	p5-GD>=2.16:../../graphics/p5-GD

PERL5_PACKLIST=		auto/Chart-ThreeD/.packlist

REPLACE_PERL+=	pie.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
