# $NetBSD: Makefile,v 1.11 2003/04/21 18:14:53 mjl Exp $
#

DISTNAME=	DBIx-SearchBuilder-0.80
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dxs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	packages@netbsd.org
COMMENT=	extension for easy SQL SELECT Statement generation

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/SearchBuilder/.packlist

DEPENDS+=	p5-Class-ReturnValue>=0.40:../../devel/p5-Class-ReturnValue

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
