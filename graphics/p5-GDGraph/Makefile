# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:21 veego Exp $
#

DISTNAME=	GDGraph-1.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gdg
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/GDGraph/Graph.html
COMMENT=	GDGraph is a package to generate charts, using Lincoln Stein's GD.pm

DEPENDS+=       p5-GDTextUtil>=0.75:../../graphics/p5-GDTextUtil

USE_PERL5=      # defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/GD/Graph/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
