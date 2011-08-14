# $NetBSD: Makefile,v 1.20 2011/08/14 14:42:50 obache Exp $
#

DISTNAME=	Module-Signature-0.66
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5ms
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Signature/
COMMENT=	Perl 5 module for module signature file manipulation
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

#DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
DEPENDS+=		{perl>=5.10.0,p5-Digest-SHA-[0-9]*}:../../security/p5-Digest-SHA
DEPENDS+=		p5-Crypt-OpenPGP>=1.00:../../security/p5-Crypt-OpenPGP

# OpenPGP dependencies used
DEPENDS+=		p5-Class-Loader-[0-9]*:../../devel/p5-Class-Loader
DEPENDS+=		p5-Convert-ASCII-Armour-[0-9]*:../../textproc/p5-Convert-ASCII-Armour
DEPENDS+=		p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1
DEPENDS+=		p5-Convert-PEM-[0-9]*:../../textproc/p5-Convert-PEM
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=		p5-Crypt-DES_EDE3-[0-9]*:../../security/p5-Crypt-DES_EDE3
DEPENDS+=		p5-Crypt-DSA>=1.16nb1:../../security/p5-Crypt-DSA
DEPENDS+=		p5-Crypt-RIPEMD160>=0.04nb4:../../security/p5-Crypt-RIPEMD160
DEPENDS+=		p5-Crypt-RSA-[0-9]*:../../security/p5-Crypt-RSA
DEPENDS+=		p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random
DEPENDS+=		p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=		p5-Crypt-Primes-[0-9]*:../../security/p5-Crypt-Primes
DEPENDS+=		p5-Crypt-Twofish>=2.00:../../security/p5-Crypt-Twofish
DEPENDS+=		p5-Data-Buffer>=0.04:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Digest-MD2-[0-9]*:../../security/p5-Digest-MD2
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-IO-Compress-[0-9]*:../../devel/p5-IO-Compress
DEPENDS+=		p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=		p5-Math-Pari-[0-9]*:../../math/p5-Math-Pari
DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/Signature/.packlist

INSTALLATION_DIRS+=	share/Module-Signature

PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_ENV+=		TEST_SIGNATURE=1

# this package has patch files so the signature check test fails
#post-extract:
#	${MV} ${WRKSRC}/t/0-signature.t ${WRKSRC}/t/0-signature.t.SKIP

post-install:
	${RUN} for f in ${WRKSRC}/*.pub; do ${INSTALL_DATA} "$$f"	\
		${DESTDIR}${PREFIX}/share/Module-Signature;		\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
