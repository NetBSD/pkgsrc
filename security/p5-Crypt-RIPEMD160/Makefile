# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:36 veego Exp $
#

DISTNAME=		Crypt-RIPEMD160-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cri
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module of the RIPEMD160 hash function

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/RIPEMD160/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
