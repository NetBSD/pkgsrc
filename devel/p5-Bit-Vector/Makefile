# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:12 veego Exp $
#

DISTNAME=	Bit-Vector-5.8
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5biv
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Bit-Vector/Vector.html
COMMENT=	Efficient base class implementing bit vectors

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Bit/Vector/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
