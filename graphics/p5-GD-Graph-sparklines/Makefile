# $NetBSD: Makefile,v 1.17 2021/05/24 19:52:24 wiz Exp $
#

DISTNAME=	GD-Graph-sparklines-0.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/GD-Graph-sparklines
COMMENT=	Perl module for creating sparklines

DEPENDS+=		p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/GD/Graph/sparklines/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
