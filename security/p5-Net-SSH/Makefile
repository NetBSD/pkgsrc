# $NetBSD: Makefile,v 1.14 2013/12/09 14:17:52 obache Exp $
#

DISTNAME=		Net-SSH-Perl-1.34
PKGNAME=		p5-Net-SSH-1.34
PKGREVISION=		5
SVR4_PKGNAME=		p5nsh
CATEGORIES=		security net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-SSH-Perl/
COMMENT=		Perl implementations of SSH1 and SSH2 protocols

DEPENDS+=		p5-Convert-PEM>=0.05:../../textproc/p5-Convert-PEM
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=		p5-Crypt-DH>=0.01:../../security/p5-Crypt-DH
DEPENDS+=		p5-Crypt-DSA>=0.11:../../security/p5-Crypt-DSA
DEPENDS+=		p5-Crypt-RSA>=1.37:../../security/p5-Crypt-RSA
DEPENDS+=		p5-Crypt-IDEA-[0-9]*:../../security/p5-Crypt-IDEA
DEPENDS+=		p5-Digest-BubbleBabble>=0.01:../../security/p5-Digest-BubbleBabble
DEPENDS+=		p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=		p5-Digest-SHA1>=2.10:../../security/p5-Digest-SHA1
DEPENDS+=		{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Math-GMP>=1.04:../../math/p5-Math-GMP
DEPENDS+=		p5-Math-Pari>=2.001804:../../math/p5-Math-Pari
DEPENDS+=		p5-String-CRC32>=1.2:../../textproc/p5-String-CRC32

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Net-SSH
PKG_SUPPORTED_OPTIONS=	idea

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Midea)
DEPENDS+=		p5-Crypt-IDEA-[0-9]*:../../security/p5-Crypt-IDEA
.endif

PERL5_PACKLIST=		auto/Net/SSH/Perl/.packlist

# no prompt from ExtUtils::MakeMaker's prompt()
MAKE_ENV+=		PERL_MM_USE_DEFAULT=true

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
