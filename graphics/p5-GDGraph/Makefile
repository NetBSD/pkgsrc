# $NetBSD: Makefile,v 1.1.1.1 2000/07/16 20:24:42 rh Exp $
#

DISTNAME=	GDGraph-1.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/GDGraph/Graph.html

DEPENDS+=       p5-GDTextUtil>=0.75:../../graphics/p5-GDTextUtil

USE_PERL5=      yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
