# $NetBSD: Makefile,v 1.6 2005/03/27 20:54:07 wiz Exp $
#

DISTNAME=		Class-MethodMaker-2.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Class-MethodMaker/
COMMENT=		Getter/setter OO method maker for class elements

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/MethodMaker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
