# $NetBSD: Makefile,v 1.1 2001/01/18 18:25:19 explorer Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:23 jfitz Exp
#

DISTNAME=		Crypt-Blowfish-2.06
PKGNAME=		p5-Crypt-Blowfish-2.06
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=		

CRYPTO=			YES

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Blowfish/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
