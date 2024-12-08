# $NetBSD: Makefile,v 1.42 2024/12/08 07:11:24 wiz Exp $

DISTNAME=		Convert-PEM-0.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Convert-PEM
COMMENT=		Perl5 module to read/write ASN.1-encoded PEM files
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Convert-ASN1>=0.10:../../textproc/p5-Convert-ASN1
DEPENDS+=		p5-Crypt-DES_EDE3-[0-9]*:../../security/p5-Crypt-DES_EDE3
DEPENDS+=		p5-CryptX-[0-9]*:../../security/p5-CryptX
DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler
TEST_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/PEM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
