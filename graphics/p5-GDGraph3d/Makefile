# $NetBSD: Makefile,v 1.6 2004/04/29 19:46:34 abs Exp $

DISTNAME=	GDGraph3d-0.56
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gd3
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
COMMENT=	GDGraph3d is a pkg to generate charts, using Lincoln Stein's GD.pm

DEPENDS+=       p5-GDGraph>=1.30:../../graphics/p5-GDGraph

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GD/Graph3d/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
