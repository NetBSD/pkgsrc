# $NetBSD: Makefile,v 1.37 2018/08/22 09:46:22 wiz Exp $

DISTNAME=		Crypt-OpenSSL-RSA-0.30
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL RSA functions
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-OpenSSL-Bignum-[0-9]*:../../security/p5-Crypt-OpenSSL-Bignum
DEPENDS+=		p5-Crypt-OpenSSL-Random-[0-9]*:../../security/p5-Crypt-OpenSSL-Random

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/OpenSSL/RSA/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
