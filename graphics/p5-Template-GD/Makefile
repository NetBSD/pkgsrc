# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:32 joerg Exp $
#

DISTNAME=	Template-GD-2.66
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AB/ABW/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AB/ABW/
COMMENT=	GD plugin(s) for the Template Toolkit

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Template/GD/.packlist
USE_LANGUAGES=	# none

DEPENDS+=	p5-GD>=1.14:../../graphics/p5-GD
DEPENDS+=	p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
