# $NetBSD: Makefile,v 1.11 2005/03/14 15:46:47 wiz Exp $
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
USE_BUILDLINK3=	YES

# versions before that contained a broken imlib2-config
BUILDLINK_DEPENDS.imlib2+=	imlib2>=1.2.0nb2

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Image/Imlib2/.packlist

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
