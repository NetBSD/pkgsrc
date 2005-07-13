# $NetBSD: Makefile,v 1.7 2005/07/13 18:01:38 jlam Exp $
#

DISTNAME=		Crypt-OpenSSL-Bignum-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		# empty2
PKGREVISION=		3
SVR4_PKGNAME=		p5obn
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL Bignum functions

PERL5_PACKLIST=		auto/Crypt/OpenSSL/Bignum/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
