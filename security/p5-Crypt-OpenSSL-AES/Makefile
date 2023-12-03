# $NetBSD: Makefile,v 1.29 2023/12/03 02:09:15 wen Exp $

DISTNAME=		Crypt-OpenSSL-AES-0.19
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-OpenSSL-AES
COMMENT=		Perl5 wrapper module for the OpenSSL AES functions
LICENSE=		${PERL5_LICENSE}

TOOL_DEPENDS+=		p5-Crypt-OpenSSL-Guess-[0-9]*:../../security/p5-Crypt-OpenSSL-Guess
TEST_DEPENDS+=		p5-File-Which-[0-9]*:../../devel/p5-File-Which

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/OpenSSL/AES/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
