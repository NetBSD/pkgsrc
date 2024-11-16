# $NetBSD: Makefile,v 1.7 2024/11/16 12:03:58 wiz Exp $

DISTNAME=	Data-IEEE754-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-IEEE754
COMMENT=	Pack and unpack big-endian IEEE754 floats and doubles
LICENSE=	artistic-2.0

TEST_DEPENDS+=	p5-Test-Bits-[0-9]*:../../devel/p5-Test-Bits

PERL5_PACKLIST=	auto/Data/IEEE754/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
