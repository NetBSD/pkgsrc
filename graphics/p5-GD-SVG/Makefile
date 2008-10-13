# $NetBSD: Makefile,v 1.2 2008/10/13 19:52:54 heinz Exp $
#

DISTNAME=	GD-SVG-0.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GD-SVG/
COMMENT=	Enables SVG output from scripts written using GD

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=		p5-SVG-[0-9]*:../../graphics/p5-SVG

PERL5_PACKLIST=		auto/GD/SVG/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
