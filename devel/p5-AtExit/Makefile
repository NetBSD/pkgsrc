# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:12 veego Exp $
#

DISTNAME=	AtExit-2.01
PKGNAME=	p5-AtExit-2.01
SVR4_PKGNAME=	p5ate
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AtExit/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Provides an ANSI C style atexit() function to Perl programs

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_ARCHLIB}/auto/AtExit/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
