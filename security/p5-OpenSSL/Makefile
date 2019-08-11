# $NetBSD: Makefile,v 1.19 2019/08/11 13:22:59 wiz Exp $
#

DISTNAME=		OpenSSL-0.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OE/OESI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/OpenSSL
COMMENT=		Perl5 wrapper module for the OpenSSL functions
#LICENSE=		gnu-gpl-v2 # under same terms as Perl

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/OpenSSL/.packlist

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
