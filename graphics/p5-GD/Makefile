# $NetBSD: Makefile,v 1.9 2001/10/18 15:20:21 veego Exp $
#

DISTNAME=	GD-1.32
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bd
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/GD/GD.html
COMMENT=	Perl5 interface to gd graphics library

DEPENDS+=	gd>=1.8.3:../../graphics/gd

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/GD/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
