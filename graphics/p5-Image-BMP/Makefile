# $NetBSD: Makefile,v 1.13 2017/06/05 14:24:01 ryoon Exp $

DISTNAME=	Image-BMP-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Image-BMP/
COMMENT=	Read BMP file information
#LICENSE=	non commercial use?

PERL5_PACKLIST=		auto/Image/BMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
