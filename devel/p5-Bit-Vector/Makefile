# $NetBSD: Makefile,v 1.3 2000/08/28 23:39:03 jlam Exp $
#

DISTNAME=	Bit-Vector-5.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Bit-Vector/Vector.html

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Bit/Vector/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
