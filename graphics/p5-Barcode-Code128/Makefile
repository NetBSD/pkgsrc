# $NetBSD: Makefile,v 1.16 2022/06/28 11:34:03 wiz Exp $

DISTNAME=	Barcode-Code128-2.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WR/WRW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Barcode-Code128
COMMENT=	Generate CODE 128 bar codes
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Barcode/Code128/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
