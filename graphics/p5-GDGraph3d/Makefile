# $NetBSD: Makefile,v 1.4 2002/03/13 17:37:14 fredb Exp $

DISTNAME=	GDGraph3d-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5gd3
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
COMMENT=	GDGraph3d is a pkg to generate charts, using Lincoln Stein's GD.pm

DEPENDS+=       p5-GDGraph>=1.30:../../graphics/p5-GDGraph

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GD/Graph3d/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
