# $NetBSD: Makefile,v 1.16 2013/05/31 12:40:08 wiz Exp $

DISTNAME=	Class-Data-Inheritable-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5cdi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Data-Inheritable/
COMMENT=	Inheritable, overridable class data
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/Class/Data/Inheritable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
