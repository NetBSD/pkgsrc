# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:27 veego Exp $

DISTNAME=	Math-Interpolate-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5min
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for interpolating data

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Math/Interpolate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

