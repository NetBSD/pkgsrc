# $NetBSD: Makefile,v 1.17 2005/04/11 21:46:07 tv Exp $
#

DISTNAME=	Image-Size-2.992
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5isi
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Size/
COMMENT=	Read the dimensions of an image in several popular formats

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
