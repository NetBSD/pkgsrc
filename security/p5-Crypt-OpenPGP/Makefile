# $NetBSD: Makefile,v 1.38 2019/06/30 20:16:38 nia Exp $

DISTNAME=		Crypt-OpenPGP-1.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-OpenPGP
COMMENT=		Pure-Perl OpenPGP implementation
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-CAST5_PP-[0-9]*:../../security/p5-Crypt-CAST5_PP
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=		p5-Crypt-DES_EDE3-[0-9]*:../../security/p5-Crypt-DES_EDE3
DEPENDS+=		p5-Crypt-DSA>=1.16nb1:../../security/p5-Crypt-DSA
DEPENDS+=		p5-Crypt-RIPEMD160>=0.04nb4:../../security/p5-Crypt-RIPEMD160
DEPENDS+=		p5-Crypt-RSA-[0-9]*:../../security/p5-Crypt-RSA
DEPENDS+=		p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=		p5-Crypt-Twofish>=2.00:../../security/p5-Crypt-Twofish
DEPENDS+=		p5-Data-Buffer>=0.04:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
#DEPENDS+=		{perl>=5.9.3,p5-IO-Compress-[0-9]*}:../../devel/p5-IO-Compress	# Compress::Zlib
DEPENDS+=		p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
#DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
# contains LWP::UserAgent
DEPENDS+=		p5-libwww>=5.10:../../www/p5-libwww

BUILD_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/OpenPGP/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
