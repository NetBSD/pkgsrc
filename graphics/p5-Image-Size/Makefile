# $NetBSD: Makefile,v 1.16 2004/12/20 11:31:04 grant Exp $
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

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
