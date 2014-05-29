# $NetBSD: Makefile,v 1.6 2014/05/29 23:35:42 wiz Exp $

DISTNAME=	Class-Accessor-Lite-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor-Lite/
COMMENT=	Minimalistic variant of Class::Accessor
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/Accessor/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
