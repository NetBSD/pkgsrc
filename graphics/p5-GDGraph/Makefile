# $NetBSD: Makefile,v 1.3 2000/11/29 00:47:42 david Exp $
#

DISTNAME=	GDGraph-1.33
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/GDGraph/Graph.html

DEPENDS+=       p5-GDTextUtil>=0.75:../../graphics/p5-GDTextUtil

USE_PERL5=      # defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/GD/Graph/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
