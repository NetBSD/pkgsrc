# $NetBSD: Makefile,v 1.8 2002/10/20 23:35:09 seb Exp $

DISTNAME=	Params-Validate-0.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pva
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Attribute/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Validate method/function parameters

DEPENDS+=	p5-Attribute-Handlers>=0.76:../../devel/p5-Attribute-Handlers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Params/Validate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
