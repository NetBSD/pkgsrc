# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:07 tv Exp $

DISTNAME=	Chart-ThreeD-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5c3d
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Chart-ThreeD/
COMMENT=	Three-Dimentional pie chart plotting

DEPENDS+=	p5-GD>=2.16:../../graphics/p5-GD

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Chart-ThreeD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
