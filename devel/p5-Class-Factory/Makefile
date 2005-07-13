# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:23 jlam Exp $

DISTNAME=	Class-Factory-1.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5clf
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Factory/
COMMENT=	Base class for dynamic factory classes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/Factory/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
