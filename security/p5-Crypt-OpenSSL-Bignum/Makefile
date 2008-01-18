# $NetBSD: Makefile,v 1.10 2008/01/18 05:09:39 tnn Exp $
#

DISTNAME=		Crypt-OpenSSL-Bignum-0.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5obn
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL Bignum functions

#LICENSE=		gnu-gpl-v2 # under same terms as Perl

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/OpenSSL/Bignum/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
