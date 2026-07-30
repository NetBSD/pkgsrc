# $NetBSD: Makefile,v 1.56 2026/07/30 10:59:45 wen Exp $

DISTNAME=		Crypt-OpenSSL-RSA-0.41
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TI/TIMLEGGE/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL RSA functions
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-OpenSSL-Bignum-[0-9]*:../../security/p5-Crypt-OpenSSL-Bignum
DEPENDS+=		p5-Crypt-OpenSSL-Random-[0-9]*:../../security/p5-Crypt-OpenSSL-Random

USE_LANGUAGES=		c
MAKE_ENV+=		DYLD_LIBRARY_PATH=${PREFIX}/lib # build on macOS

PERL5_PACKLIST=		auto/Crypt/OpenSSL/RSA/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
