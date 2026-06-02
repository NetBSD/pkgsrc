# $NetBSD: Makefile,v 1.1 2026/06/02 13:23:06 taca Exp $
#

DISTNAME=		Crypt-OpenSSL-X509-2.0.1
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dsully/perl-crypt-openssl-x509
COMMENT=		Perl extension to OpenSSL's X509 API
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Crypt/OpenSSL/X509/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
