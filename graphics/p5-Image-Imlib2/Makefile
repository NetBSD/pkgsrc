# $NetBSD: Makefile,v 1.48 2017/06/05 14:24:01 ryoon Exp $
#

DISTNAME=	Image-Imlib2-2.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
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
