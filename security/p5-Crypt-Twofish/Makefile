# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:37 veego Exp $
#

DISTNAME=		Crypt-Twofish-2.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ctw
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for the Twofish symmetric key algorithm

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Twofish/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
