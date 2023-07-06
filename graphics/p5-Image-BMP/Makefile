# $NetBSD: Makefile,v 1.20 2023/07/06 09:40:39 wiz Exp $

DISTNAME=	Image-BMP-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Image-BMP
COMMENT=	Read BMP file information
#LICENSE=	non commercial use?

PERL5_PACKLIST=		auto/Image/BMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
