# $NetBSD: Makefile,v 1.1.1.1 2003/08/30 18:56:46 he Exp $

DISTNAME=	Class-Container-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ccr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/author/KWILLIAMS/Class-Container-0.10/
COMMENT=	Glues object frameworks together transparently

DEPENDS+=	p5-Params-Validate>=0.23:../../devel/p5-Params-Validate

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Container/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
