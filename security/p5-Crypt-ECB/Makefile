# $NetBSD: Makefile,v 1.27 2024/02/28 07:40:50 wen Exp $

DISTNAME=		Crypt-ECB-2.23
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-ECB
COMMENT=		Perl5 Electronic Codebook mode for various crypto algorithms
LICENSE=		gnu-gpl-v1 OR artistic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/ECB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
