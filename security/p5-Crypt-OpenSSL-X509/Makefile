# $NetBSD: Makefile,v 1.2 2026/06/07 13:35:24 wiz Exp $

DISTNAME=		Crypt-OpenSSL-X509-2.0.1
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dsully/perl-crypt-openssl-x509
COMMENT=		Perl extension to OpenSSL's X509 API
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-OpenSSL-Guess-[0-9]*:../../security/p5-Crypt-OpenSSL-Guess
DEPENDS+=		p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1

PERL5_PACKLIST=		auto/Crypt/OpenSSL/X509/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
