# $NetBSD: Makefile,v 1.1.1.1 2001/03/05 21:44:14 jtb Exp $

DISTNAME=	GDGraph3d-0.55
PKGNAME=	p5-${DISTNAME}
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
