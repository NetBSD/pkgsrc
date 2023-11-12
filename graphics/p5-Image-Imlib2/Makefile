# $NetBSD: Makefile,v 1.58 2023/11/12 13:22:10 wiz Exp $
#

DISTNAME=	Image-Imlib2-2.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	24
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Image-Imlib2
COMMENT=	Interface to the Imlib2 image library
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.9.1

PERL5_PACKLIST=		auto/Image/Imlib2/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
