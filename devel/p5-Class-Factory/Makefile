# $NetBSD: Makefile,v 1.14 2012/10/31 11:17:47 asau Exp $

DISTNAME=	Class-Factory-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5clf
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Factory/
COMMENT=	Base class for dynamic factory classes
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/Factory/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
