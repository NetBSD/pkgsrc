# $NetBSD: Makefile,v 1.15 2024/02/28 07:43:06 wen Exp $
#

DISTNAME=	Crypt-URandom-0.40
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-URandom
COMMENT=	Perl5 module to provide non blocking randomness
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Crypt/URandom/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
