# $NetBSD: Makefile,v 1.9 2005/07/13 18:01:27 jlam Exp $
#

DISTNAME=	Module-Dependency-1.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Build perl program/module dependency graph

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable
DEPENDS+=	p5-GD>=1.32nb1:../../graphics/p5-GD

PERL5_PACKLIST=		auto/Module/Dependency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
