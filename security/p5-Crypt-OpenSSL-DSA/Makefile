# $NetBSD: Makefile,v 1.4 2004/10/03 00:18:11 tv Exp $
#

DISTNAME=		Crypt-OpenSSL-DSA-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		# empty2
PKGREVISION=		2
SVR4_PKGNAME=		p5ods
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL DSA functions

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/OpenSSL/DSA/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
