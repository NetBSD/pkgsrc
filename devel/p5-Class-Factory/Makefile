# $NetBSD: Makefile,v 1.2 2004/11/29 20:52:39 wiz Exp $

DISTNAME=	Class-Factory-1.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5clf
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Factory/
COMMENT=	Base class for dynamic factory classes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/Factory/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
