# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:42 veego Exp $

DISTNAME=       Text-Autoformat-1.04
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tau
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.monash.edu.au/~damian/
COMMENT=	perl module for text wrapping and reformatting

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/Autoformat/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
