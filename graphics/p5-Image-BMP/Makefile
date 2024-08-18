# $NetBSD: Makefile,v 1.21 2024/08/18 09:37:19 wen Exp $

DISTNAME=	Image-BMP-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Image-BMP
COMMENT=	Read BMP file information
#LICENSE=	non commercial use?

PERL5_PACKLIST=		auto/Image/BMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
