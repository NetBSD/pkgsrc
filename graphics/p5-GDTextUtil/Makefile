# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:21 veego Exp $
#

DISTNAME=	GDTextUtil-0.80
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gdt
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theoryx5.uwinnipeg.ca/CPAN/data/GDTextUtil/Text.html
COMMENT=	Perl 5 text utilities for use with the GD drawing package

DEPENDS+=	p5-GD>=1.30:../../graphics/p5-GD

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/GD/Text/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
