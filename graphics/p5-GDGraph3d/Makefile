# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:21 veego Exp $

DISTNAME=	GDGraph3d-0.55
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gd3
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
COMMENT=	GDGraph3d is a pkg to generate charts, using Lincoln Stein's GD.pm

DEPENDS+=       p5-GDGraph>=1.30:../../graphics/p5-GDGraph

USE_PERL5=      # defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/GD/Graph3d/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
