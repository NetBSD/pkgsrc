# $NetBSD: Makefile,v 1.1.1.1 2001/03/20 14:07:14 wiz Exp $
#

DISTNAME=		Crypt-DES-2.03
PKGNAME=		p5-Crypt-DES-2.03
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		XS-based DES implementation for Perl

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/DES/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
