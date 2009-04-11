# $NetBSD: Makefile,v 1.19 2009/04/11 23:15:21 sno Exp $
#

DISTNAME=		Crypt-OpenPGP-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
SVR4_PKGNAME=		p5pgp
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-OpenPGP/
COMMENT=		Perl5 module for OpenPGP support

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-IO-Compress-[0-9]*:../../devel/p5-IO-Compress
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-CAST5_PP-[0-9]*:../../security/p5-Crypt-CAST5_PP
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=		p5-Crypt-DES_EDE3-[0-9]*:../../security/p5-Crypt-DES_EDE3
DEPENDS+=		p5-Crypt-DSA-[0-9]*:../../security/p5-Crypt-DSA
DEPENDS+=		p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=		p5-Crypt-RIPEMD160-[0-9]*:../../security/p5-Crypt-RIPEMD160
DEPENDS+=		p5-Crypt-RSA-[0-9]*:../../security/p5-Crypt-RSA
DEPENDS+=		p5-Crypt-Twofish>=2.00:../../security/p5-Crypt-Twofish
DEPENDS+=		p5-Data-Buffer>=0.04:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
# contains LWP::UserAgent
DEPENDS+=		p5-libwww>=5.10:../../www/p5-libwww
DEPENDS+=		p5-Math-Pari-[0-9]*:../../math/p5-Math-Pari
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
# hmmm
#DEPENDS+=		p5-Crypt-IDEA-[0-9]*:../../security/p5-Crypt-IDEA

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--skipdeps
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/OpenPGP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
