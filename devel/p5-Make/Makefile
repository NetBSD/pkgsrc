# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:17 veego Exp $

DISTNAME=	Make-1.00
PKGNAME=	p5-Make-1.00
SVR4_PKGNAME=	p5mak
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Make/}

MAINTAINER=	packages@netbd.org
HOMEPAGE=	http://www.ni-s.u-net.com/
COMMENT=	Perl5 module implementing 'make' in Perl

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Make/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
