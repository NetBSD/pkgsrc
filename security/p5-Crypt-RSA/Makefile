# $NetBSD: Makefile,v 1.1 2001/10/01 00:42:53 mcr Exp $
#

DISTNAME=		Crypt-RSA-1.47
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module of the RSA public key algorithm

DEPENDS+=		p5-Math-Pari-*:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Random-*:../../security/p5-Crypt-Random
DEPENDS+=		p5-Crypt-Primes-*:../../security/p5-Crypt-Primes
DEPENDS+=		p5-Tie-EncryptedHash-*:../../security/p5-Tie-EncryptedHash
DEPENDS+=		p5-Convert-ASCII-Armour-*:../../converters/p5-Convert-ASCII-Armour
DEPENDS+=		p5-SortVersions-*:../../devel/p5-SortVersions
#DEPENDS+=		p5-Digest-SHA1-*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Digest-MD5-*:../../security/p5-Digest-MD5
#DEPENDS+=		p5-Digest-MD2-*:../../security/p5-Digest-MD2
DEPENDS+=		p5-Class-Loader-*:../../devel/p5-Class-Loader
DEPENDS+=		p5-Data-Buffer-*:../../devel/p5-Data-Buffer

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/RSA/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
