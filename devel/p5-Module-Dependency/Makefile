# $NetBSD: Makefile,v 1.2 2002/10/20 23:20:21 seb Exp $
#

DISTNAME=	Module-Dependency-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Build perl program/module dependency graph

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable
DEPENDS+=	p5-GD>=1.32nb1:../../graphics/p5-GD

USE_BUILDLINK2=		 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Module/Dependency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
