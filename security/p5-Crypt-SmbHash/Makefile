# $NetBSD: Makefile,v 1.21 2023/07/06 09:41:25 wiz Exp $
#

DISTNAME=		Crypt-SmbHash-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-SmbHash
COMMENT=		Perl5 module for generating LM/NT hashes

DEPENDS+=		p5-Digest-MD4>=1.3:../../security/p5-Digest-MD4

PERL5_PACKLIST=		auto/Crypt/SmbHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
