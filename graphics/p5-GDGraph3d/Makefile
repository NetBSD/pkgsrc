# $NetBSD: Makefile,v 1.5 2002/10/27 21:20:39 seb Exp $

DISTNAME=	GDGraph3d-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
