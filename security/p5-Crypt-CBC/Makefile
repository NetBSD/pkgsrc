# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:35 veego Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:23 jfitz Exp
#

DISTNAME=		Crypt-CBC-1.25
PKGNAME=		p5-Crypt-CBC-1.25
SVR4_PKGNAME=		p5cbc
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 cipher block chaining mode for various crypto algorithms

DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/CBC/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
