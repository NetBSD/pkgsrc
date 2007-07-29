# $NetBSD: Makefile,v 1.1.1.1 2007/07/29 12:16:53 adrianp Exp $
#

DISTNAME=	Template-GD-2.66
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AB/ABW/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AB/ABW/
COMMENT=	GD plugin(s) for the Template Toolkit

PERL5_PACKLIST=	auto/Template/GD/.packlist
USE_LANGUAGES=	# none

DEPENDS+=	p5-GD>=1.14:../../graphics/p5-GD
DEPENDS+=	p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
