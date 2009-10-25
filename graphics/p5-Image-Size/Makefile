# $NetBSD: Makefile,v 1.26 2009/10/25 13:11:16 sno Exp $
#

DISTNAME=	Image-Size-3.210
PKGNAME=	p5-${DISTNAME:S/210/2.1/}
SVR4_PKGNAME=	p5isi
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Size/
COMMENT=	Read the dimensions of an image in several popular formats
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress

BUILD_DEPENDS+=	p5-Test-Simple>=0.80:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Image/Size/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
