# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:36 veego Exp $
#

DISTNAME=		Crypt-RSA-1.47
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5rsa
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module of the RSA public key algorithm

DEPENDS+=		p5-Math-Pari-[0-9]*:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random
DEPENDS+=		p5-Crypt-Primes-[0-9]*:../../security/p5-Crypt-Primes
DEPENDS+=		p5-Tie-EncryptedHash-[0-9]*:../../security/p5-Tie-EncryptedHash
DEPENDS+=		p5-Convert-ASCII-Armour-[0-9]*:../../textproc/p5-Convert-ASCII-Armour
DEPENDS+=		p5-SortVersions-[0-9]*:../../devel/p5-SortVersions
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5
DEPENDS+=		p5-Digest-MD2-[0-9]*:../../security/p5-Digest-MD2
DEPENDS+=		p5-Class-Loader-[0-9]*:../../devel/p5-Class-Loader
DEPENDS+=		p5-Data-Buffer-[0-9]*:../../devel/p5-Data-Buffer

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/RSA/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
