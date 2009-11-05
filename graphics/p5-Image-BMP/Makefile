# $NetBSD: Makefile,v 1.1.1.1 2009/11/05 22:47:47 wiz Exp $
#

DISTNAME=	Image-BMP-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Image-BMP/
COMMENT=	Read BMP file information
#LICENSE=	non commercial use?

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Image/BMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
