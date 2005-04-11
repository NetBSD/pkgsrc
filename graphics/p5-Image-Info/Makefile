# $NetBSD: Makefile,v 1.11 2005/04/11 21:46:07 tv Exp $
#

DISTNAME=	Image-Info-1.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iin
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Info/
COMMENT=	Perl module to extract meta information from images

DEPENDS+=	p5-IO-String>=1.03:../../devel/p5-IO-String

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
