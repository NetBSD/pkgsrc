# $NetBSD: Makefile,v 1.9 2005/07/13 18:01:23 jlam Exp $

DISTNAME=	Class-ObjectTemplate-0.7
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cot
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-ObjectTemplate/
COMMENT=	Perl extension for optimized template builder base class

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/ObjectTemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
