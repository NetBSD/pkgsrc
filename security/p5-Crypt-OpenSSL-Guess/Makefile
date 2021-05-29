# $NetBSD: Makefile,v 1.7 2021/05/29 10:44:26 wen Exp $
#

DISTNAME=		Crypt-OpenSSL-Guess-0.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/akiym/Crypt-OpenSSL-Guess
COMMENT=		Guess OpenSSL include path
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Crypt/OpenSSL/Guess/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
