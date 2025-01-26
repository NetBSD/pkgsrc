# $NetBSD: Makefile,v 1.20 2025/01/26 07:32:23 wiz Exp $

DISTNAME=	Crypt-URandom-0.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-URandom
COMMENT=	Perl5 module to provide non blocking randomness
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Crypt/URandom/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
