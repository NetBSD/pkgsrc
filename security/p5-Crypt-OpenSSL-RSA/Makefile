# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 22:03:22 heinz Exp $
#

DISTNAME=		Crypt-OpenSSL-RSA-0.19
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ors
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL RSA functions

DEPENDS+=		p5-Crypt-OpenSSL-Bignum-[0-9]*:../p5-Crypt-OpenSSL-Bignum
DEPENDS+=		p5-Crypt-OpenSSL-Random-[0-9]*:../p5-Crypt-OpenSSL-Random

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/OpenSSL/RSA/.packlist

.include "../../security/openssl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
