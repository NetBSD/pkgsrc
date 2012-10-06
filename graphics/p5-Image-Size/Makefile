# $NetBSD: Makefile,v 1.32 2012/10/06 14:11:12 asau Exp $
#

DISTNAME=	Image-Size-3.230
PKGNAME=	p5-${DISTNAME:S/220/2.2/}
PKGREVISION=	2
SVR4_PKGNAME=	p5isi
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Size/
COMMENT=	Read the dimensions of an image in several popular formats
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress

BUILD_DEPENDS+=	{perl>=5.10.0,p5-Test-Simple>=0.80}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Image/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
