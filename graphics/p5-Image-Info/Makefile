# $NetBSD: Makefile,v 1.3 2002/10/20 17:46:06 seb Exp $
#

DISTNAME=	Image-Info-1.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iin
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Info/
COMMENT=	perl module to extract meta information from images

DEPENDS+=	p5-IO-String>=1.01:../../devel/p5-IO-String

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
