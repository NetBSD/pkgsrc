# $NetBSD: Makefile,v 1.23 2021/05/24 19:53:58 wiz Exp $
#

DISTNAME=		Crypt-OpenSSL-AES-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		18
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-OpenSSL-AES
COMMENT=		Perl5 wrapper module for the OpenSSL AES functions
#LICENSE=		gnu-gpl-v2 # under same terms as Perl

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/OpenSSL/AES/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
