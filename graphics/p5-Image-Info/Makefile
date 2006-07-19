# $NetBSD: Makefile,v 1.16 2006/07/19 22:40:27 wiz Exp $
#

DISTNAME=	Image-Info-1.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iin
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Info/
COMMENT=	Perl module to extract meta information from images

DEPENDS+=	p5-IO-String>=1.03:../../devel/p5-IO-String

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Image/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
