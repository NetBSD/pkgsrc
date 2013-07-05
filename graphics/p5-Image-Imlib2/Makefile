# $NetBSD: Makefile,v 1.43 2013/07/05 13:29:36 ryoon Exp $
#

DISTNAME=	Image-Imlib2-2.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
SVR4_PKGNAME=	p5im2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Image-Imlib2/
COMMENT=	Interface to the Imlib2 image library
LICENSE=	${PERL5_LICENSE}

# versions before that contained a broken imlib2-config
BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.2.0nb2

PERL5_PACKLIST=		auto/Image/Imlib2/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
