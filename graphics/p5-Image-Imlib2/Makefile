# $NetBSD: Makefile,v 1.12 2005/04/11 21:46:07 tv Exp $
#

DISTNAME=	Image-Imlib2-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5im2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Imlib2/
COMMENT=	Interface to the Imlib2 image library

USE_PERL5=	run
USE_X11=	YES

# versions before that contained a broken imlib2-config
BUILDLINK_DEPENDS.imlib2+=	imlib2>=1.2.0nb2

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Imlib2/.packlist

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
