# $NetBSD: Makefile,v 1.8 2005/04/18 16:10:06 wiz Exp $

DISTNAME=	Module-Build-0.2610
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mob
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Build/
COMMENT=	Build and install Perl modules

DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Module/Build/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
