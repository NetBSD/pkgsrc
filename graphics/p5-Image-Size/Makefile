# $NetBSD: Makefile,v 1.11 2003/01/31 10:24:51 shell Exp $
#

DISTNAME=	Image-Size-2.991
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5isi
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Size/
COMMENT=	Read the dimensions of an image in several popular formats

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
