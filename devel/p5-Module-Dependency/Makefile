# $NetBSD: Makefile,v 1.6 2004/04/27 04:59:42 snj Exp $
#

DISTNAME=	Module-Dependency-1.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Build perl program/module dependency graph

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable
DEPENDS+=	p5-GD>=1.32nb1:../../graphics/p5-GD

USE_BUILDLINK3=		 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Module/Dependency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
