# $NetBSD: Makefile,v 1.10 2002/10/07 22:34:26 seb Exp $
#

DISTNAME=	Image-Size-2.98
PKGNAME=	p5-${DISTNAME}0
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
