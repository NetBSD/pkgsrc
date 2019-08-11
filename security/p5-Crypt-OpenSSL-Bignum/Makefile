# $NetBSD: Makefile,v 1.33 2019/08/11 13:22:52 wiz Exp $

DISTNAME=		Crypt-OpenSSL-Bignum-0.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL Bignum functions
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/OpenSSL/Bignum/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
