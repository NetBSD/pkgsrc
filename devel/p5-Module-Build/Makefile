# $NetBSD: Makefile,v 1.6 2005/02/24 22:38:42 jlam Exp $

DISTNAME=	Module-Build-0.2608
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mob
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Build/
COMMENT=	Build and install Perl modules

DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

USE_BUILDLINK3=		yes
BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Module/Build/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
