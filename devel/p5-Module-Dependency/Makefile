# $NetBSD: Makefile,v 1.1.1.1 2002/03/25 05:55:52 cjs Exp $
#

DISTNAME=	Module-Dependency-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Build perl program/module dependency graph

DEPENDS+=	p5-Storable>=1.0.14:../../devel/p5-Storable

USE_BUILDLINK_ONLY=	 YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Module/Dependency/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL </dev/null

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
