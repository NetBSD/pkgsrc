# $NetBSD: Makefile,v 1.2 2001/10/02 16:59:05 mcr Exp $
#

DISTNAME=		Crypt-DSA-0.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for the DSA public key algorithm

# XXX: really want p5-Digest-SHA1...waiting for update
DEPENDS+=		p5-Digest-MD5-*:../../security/p5-Digest-MD5
DEPENDS+=		p5-Math-Pari-*:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Random-*:../../security/p5-Crypt-Random
DEPENDS+=		p5-Data-Buffer-*:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Convert-PEM-*:../../textproc/p5-Convert-PEM

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/DSA/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
