# $NetBSD: Makefile,v 1.18 2018/08/22 09:46:22 wiz Exp $
#

DISTNAME=		Crypt-OpenSSL-AES-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-OpenSSL-AES/
COMMENT=		Perl5 wrapper module for the OpenSSL AES functions
#LICENSE=		gnu-gpl-v2 # under same terms as Perl

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Crypt/OpenSSL/AES/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
