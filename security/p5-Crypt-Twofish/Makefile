# $NetBSD: Makefile,v 1.1.1.1 2001/09/20 00:45:58 mjl Exp $
#

DISTNAME=		Crypt-Twofish-2.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module for the Twofish symmetric key algorithm

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Twofish/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
