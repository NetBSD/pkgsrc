# $NetBSD: Makefile,v 1.29 2016/06/08 19:24:20 wiz Exp $
#

DISTNAME=		Crypt-OpenSSL-DSA-0.15
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://perl-openssl.sourceforge.net/
COMMENT=		Perl5 wrapper module for the OpenSSL DSA functions
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Crypt/OpenSSL/DSA/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
