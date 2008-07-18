# $NetBSD: Makefile,v 1.22 2008/07/18 15:07:13 rhaen Exp $
#

DISTNAME=	Image-Size-3.1.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5isi
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Size/
COMMENT=	Read the dimensions of an image in several popular formats

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
DEPENDS+=	p5-Compress-Zlib>=2:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=		auto/Image/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
