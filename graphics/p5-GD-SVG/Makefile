# $NetBSD: Makefile,v 1.7 2012/10/03 21:56:12 wiz Exp $
#

DISTNAME=	GD-SVG-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GD-SVG/
COMMENT=	Enables SVG output from scripts written using GD
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=		p5-SVG-[0-9]*:../../graphics/p5-SVG

PERL5_PACKLIST=		auto/GD/SVG/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
