# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:15 veego Exp $

DISTNAME=	Event-0.81
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5eve
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Event library for Perl

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Event/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
