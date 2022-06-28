# $NetBSD: Makefile,v 1.16 2022/06/28 11:34:04 wiz Exp $

DISTNAME=	GD-Barcode-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/GD-Barcode
COMMENT=	Create barcode image with GD
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/GD/Barcode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
