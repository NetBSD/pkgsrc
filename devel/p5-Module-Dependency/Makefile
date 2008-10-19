# $NetBSD: Makefile,v 1.14 2008/10/19 19:17:56 he Exp $
#

DISTNAME=	Module-Dependency-1.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Build perl program/module dependency graph

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable
DEPENDS+=	p5-GD>=1.32nb1:../../graphics/p5-GD

PERL5_PACKLIST=		auto/Module/Dependency/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
