# $NetBSD: Makefile,v 1.23 2008/08/03 21:07:21 he Exp $
#

DISTNAME=	Image-Imlib2-2.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5im2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Image-Imlib2/
#HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Imlib2/
COMMENT=	Interface to the Imlib2 image library

PKG_DESTDIR_SUPPORT=	user-destdir

# versions before that contained a broken imlib2-config
BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.2.0nb2

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/Image/Imlib2/.packlist

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
