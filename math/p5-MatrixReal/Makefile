# $NetBSD: Makefile,v 1.2 2001/02/17 18:22:35 wiz Exp $

DISTNAME=	Math-MatrixReal-1.3a5
PKGNAME=	p5-MatrixReal-1.3a5
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	jtb@netbsd.org
COMMENT=	Perl module for performing operations on real matrices

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Math/MatrixReal/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

