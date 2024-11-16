# $NetBSD: Makefile,v 1.47 2024/11/16 12:06:42 wiz Exp $

DISTNAME=		Convert-ASN1-0.34
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Convert-ASN1
COMMENT=		Perl5 module to encode/decode ASN.1 data
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/ASN1/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
