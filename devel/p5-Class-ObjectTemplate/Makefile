# $NetBSD: Makefile,v 1.2 2002/10/13 22:22:51 seb Exp $

DISTNAME=	Class-ObjectTemplate-0.4
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cot
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.oreilly.com/catalog/advperl/
COMMENT=	Perl extension for optimized template builder base class

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/ObjectTemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
