# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:15 veego Exp $

DISTNAME=	ExtUtils-F77-1.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for determining how to link Fortran and C

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/ExtUtils/F77/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

