# $NetBSD: Makefile,v 1.5 2002/07/02 11:41:57 agc Exp $
#

DISTNAME=		Crypt-OpenPGP-0.17
PKGNAME=                p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5pgp
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for OpenPGP support

DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=		p5-Crypt-DES_EDE3-[0-9]*:../../security/p5-Crypt-DES_EDE3
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Data-Buffer-[0-9]*:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Math-Pari-[0-9]*:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Twofish-[0-9]*:../../security/p5-Crypt-Twofish
DEPENDS+=		p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=		p5-Crypt-RIPEMD160-[0-9]*:../../security/p5-Crypt-RIPEMD160
DEPENDS+=		p5-Crypt-RSA-[0-9]*:../../security/p5-Crypt-RSA
DEPENDS+=		p5-Crypt-DSA-[0-9]*:../../security/p5-Crypt-DSA
# hmmm
#DEPENDS+=		p5-Crypt-IDEA-[0-9]*:../../security/p5-Crypt-IDEA

INTERACTIVE_STAGE=	configure # need to select ciphers and digests

USE_PERL5=		# defined
# more than one?
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/OpenPGP/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
