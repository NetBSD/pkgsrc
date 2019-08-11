# $NetBSD: Makefile,v 1.3 2019/08/11 13:22:52 wiz Exp $
#

DISTNAME=		Crypt-OpenSSL-Guess-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
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
