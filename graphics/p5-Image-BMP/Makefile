# $NetBSD: Makefile,v 1.3 2011/08/14 12:59:50 obache Exp $
#

DISTNAME=	Image-BMP-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
