# $NetBSD: Makefile,v 1.2 2004/11/12 17:36:40 seb Exp $

DISTNAME=	Chart-ThreeD-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5c3d
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Chart-ThreeD/
COMMENT=	Three-Dimentional pie chart plotting

DEPENDS+=	p5-GD>=2.16:../../graphics/p5-GD

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Chart-ThreeD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
