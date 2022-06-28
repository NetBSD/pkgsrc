# $NetBSD: Makefile,v 1.42 2022/06/28 11:35:45 wiz Exp $

DISTNAME=		Crypt-Rijndael-1.16
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-Rijndael
COMMENT=		Crypt::CBC compliant Rijndael encryption module
LICENSE=		gnu-lgpl-v3

DEPENDS+=		p5-Test-Manifest>=1.14:../../devel/p5-Test-Manifest

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/Rijndael/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
