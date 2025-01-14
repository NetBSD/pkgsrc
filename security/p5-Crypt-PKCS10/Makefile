# $NetBSD: Makefile,v 1.1 2025/01/14 09:49:01 wiz Exp $

DISTNAME=	Crypt-PKCS10-2.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MR/MRSCOTTY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-PKCS10
COMMENT=	Parse PKCS #10 certificate requests
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Convert-ASN1>=0:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-CryptX>=0:../../security/p5-CryptX

PERL5_PACKLIST=		auto/Crypt/PKCS10/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
