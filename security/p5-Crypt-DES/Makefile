# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:35 veego Exp $
#

DISTNAME=		Crypt-DES-2.03
PKGNAME=		p5-Crypt-DES-2.03
SVR4_PKGNAME=		p5des
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		XS-based DES implementation for Perl

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/DES/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
