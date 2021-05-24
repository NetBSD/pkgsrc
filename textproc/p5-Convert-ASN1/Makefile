# $NetBSD: Makefile,v 1.42 2021/05/24 19:54:27 wiz Exp $
#

DISTNAME=		Convert-ASN1-0.27
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		converters perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Convert-ASN1
COMMENT=		Perl5 module to encode/decode ASN.1 data
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/ASN1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
