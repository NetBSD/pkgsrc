# $NetBSD: Makefile,v 1.11 2016/06/08 19:23:53 wiz Exp $
#

DISTNAME=	GD-Graph-sparklines-0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GD-Graph-sparklines/
COMMENT=	Perl module for creating sparklines

DEPENDS+=		p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/GD/Graph/sparklines/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
