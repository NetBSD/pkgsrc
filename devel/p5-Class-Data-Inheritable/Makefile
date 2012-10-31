# $NetBSD: Makefile,v 1.15 2012/10/31 11:17:46 asau Exp $

DISTNAME=	Class-Data-Inheritable-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
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
