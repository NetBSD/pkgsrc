# $NetBSD: Makefile,v 1.1 2025/01/16 17:59:42 wiz Exp $

DISTNAME=	Crypt-LE-0.39
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security sysutils www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEADER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-LE
#HOMEPAGE=	https://github.com/do-know/Crypt-LE
COMMENT=	Let's Encrypt (and other ACME-based) API interfacing module and client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Convert-ASN1>=0.2:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-Crypt-OpenSSL-Bignum>=0.07:../../security/p5-Crypt-OpenSSL-Bignum
DEPENDS+=	p5-Crypt-OpenSSL-RSA>=0.28:../../security/p5-Crypt-OpenSSL-RSA
DEPENDS+=	p5-IO-Socket-SSL>=1.42:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-JSON-MaybeXS>=1.003005:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-Log-Log4perl>=1.27:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Net-SSLeay>=1.55:../../security/p5-Net-SSLeay

PERL5_PACKLIST=		auto/Crypt/LE/.packlist
PERL5_MODULE_TYPE=	MakeMaker

REPLACE_PERL+=	script/le.pl

# needed for tests
#ALLOW_NETWORK_ACCESS=	yes

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
