# $NetBSD: Makefile,v 1.5 2000/07/14 08:53:13 rh Exp $
#

DISTNAME=	GD-1.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/GD/GD.html

DEPENDS+=	gd>=1.8.3:../../graphics/gd

USE_PERL5=	yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
