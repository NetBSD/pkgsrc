# $NetBSD: Makefile,v 1.15 2021/05/24 19:52:24 wiz Exp $

DISTNAME=	GD-Barcode-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
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
