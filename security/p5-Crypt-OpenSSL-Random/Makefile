# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 21:56:36 heinz Exp $
#

DISTNAME=		Crypt-OpenSSL-Random-0.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ord
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for OpenSSL pseudo-random number generator

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/OpenSSL/Random/.packlist

.include "../../security/openssl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
