# $NetBSD: Makefile,v 1.1 2001/10/01 00:00:08 mcr Exp $
#

DISTNAME=		Crypt-OpenPGP-0.17
PKGNAME=                p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for OpenPGP support

DEPENDS+=		p5-MIME-Base64-*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Compress-Zlib-*:../../devel/p5-Compress-Zlib
DEPENDS+=		p5-Crypt-DES-*:../../security/p5-Crypt-DES
DEPENDS+=		p5-Crypt-DES_EDE3-*:../../security/p5-Crypt-DES_EDE3
DEPENDS+=		p5-Crypt-Blowfish-*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Data-Buffer-*:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Math-Pari-*:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Twofish-*:../../security/p5-Crypt-Twofish
DEPENDS+=		p5-Crypt-Rijndael-*:../../security/p5-Crypt-Rijndael
DEPENDS+=		p5-Crypt-RIPEMD160-*:../../security/p5-Crypt-RIPEMD160
DEPENDS+=		p5-Crypt-RSA-*:../../security/p5-Crypt-RSA
DEPENDS+=		p5-Crypt-DSA-*:../../security/p5-Crypt-DSA
# hmmm
#DEPENDS+=		p5-Crypt-IDEA-*:../../security/p5-Crypt-IDEA

# hmmm
IS_INTERACTIVE=		# defined

USE_PERL5=		# defined
# more than one?
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/OpenPGP/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
